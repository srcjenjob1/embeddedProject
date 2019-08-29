#pragma once

#include <map>
#include <thread>
#include <functional>
#include "ReceivingInterface.h"
#include "SendingInterface.h"
#include "MsgMerger.h"

class ConnectionManager : public SendingInterface {
public:
    using ListenerId = uint8_t ;
    using MsgListener = std::function<void(const Msg &)>;

    ConnectionManager(SendingInterface *sendingInterface, ReceivingInterface *receivingInterface);

    virtual ~ConnectionManager();

    virtual bool sendMsg(Msg msg);

    void registerListener(ListenerId listenerId, MsgListener &&listener);

    void receivingLoop();

private:
    void sendMsgIfReady();

    SendingInterface *_sendingInterface;
    ReceivingInterface *_receivingInterface;
    std::thread listeningThread;
    bool stopReceiving;
    std::map<ListenerId, MsgListener> _listeners;
    MsgMerger merger;
};
