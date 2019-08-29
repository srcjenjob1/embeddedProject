#include <iostream>
#include "RoundTrip.h"
#include "MsgHelper.h"

RoundTrip::RoundTrip() :
        connectionManager(&i2c, &uart),
        msgSent(0),
        msgReceived(0){
    using std::placeholders::_1;
    connectionManager.registerListener(1, std::bind(&RoundTrip::receiveMsg, std::ref(*this), _1));
}

void RoundTrip::receiveMsg(const std::vector<uint8_t> &msg) {
    std::cout << "Received new msg of size " << msg.size() << "\n";
    msgReceived++;
}

bool RoundTrip::sendMsg(const std::vector<uint8_t> &msg) {
    bool result = connectionManager.sendMsg(msg);
    if(result) msgSent++;
    return result;
}

bool RoundTrip::testResult() const {
    if(msgSent==0) return false;
    return msgSent == msgReceived;
}
