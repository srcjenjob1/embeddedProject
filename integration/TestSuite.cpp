#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "SendingInterface.h"
#include "ReceivingInterface.h"
#include "ConnectionManager.h"
#include <condition_variable>

class MockedSendingInterface : public SendingInterface {
public:
    MOCK_METHOD1(sendMsg, bool(Msg));
};

class MockedReceivingInterface : public ReceivingInterface {
public:
    MOCK_METHOD0(receiveMsg, Msg());
};

class ConnectionSubsystemTest : public ::testing::Test {
public:
    void initializeConnMgr() {
        connectionManager = std::make_unique<ConnectionManager>(&sendingInterface, &receivingInterface);
    }

protected:
    MockedSendingInterface sendingInterface;
    MockedReceivingInterface receivingInterface;
    std::unique_ptr<ConnectionManager> connectionManager;
    std::mutex stepFinishedMutex;
    std::condition_variable stepFinished;
};

TEST_F(ConnectionSubsystemTest, sendingTest) {
    initializeConnMgr();
    std::vector<uint8_t> msg = {5, 1, 2, 3, 4};
    EXPECT_CALL(sendingInterface, sendMsg(msg)).Times(1);
    connectionManager->sendMsg(msg);
}

TEST_F(ConnectionSubsystemTest, receiveMsgTest) {
    using testing::Return;
    using testing::Invoke;

    ConnectionManager::ListenerId id = 44;
    Msg wholeMsg = {5, id, 2, 3, 4};
    EXPECT_CALL(receivingInterface, receiveMsg())
            .WillOnce(testing::DoAll(
                    testing::Invoke([this, id, wholeMsg]() {
                        connectionManager->registerListener(id, [wholeMsg](const std::vector<uint8_t> &msg) {
                            EXPECT_EQ(msg, wholeMsg);
                        });
                    }),
                    Return(Msg{5, id, 2})))
            .WillOnce(testing::DoAll(
                    Invoke([this]() { stepFinished.notify_one(); }),
                    Return(Msg{3, 4})))
            .WillRepeatedly(Return(Msg{}));

    initializeConnMgr();
    std::unique_lock<std::mutex> guard(stepFinishedMutex);
    stepFinished.wait_for(guard, std::chrono::milliseconds(100));
}

