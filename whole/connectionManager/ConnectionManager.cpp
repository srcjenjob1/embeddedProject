#include "ConnectionManager.h"
#include <iostream>
#include "MsgHelper.h"

ConnectionManager::ConnectionManager(SendingInterface *sendingInterface, ReceivingInterface *receivingInterface) :
        _sendingInterface(sendingInterface),
        _receivingInterface(receivingInterface),
        stopReceiving(false) {

    listeningThread = std::thread(&ConnectionManager::receivingLoop, this);
}

ConnectionManager::~ConnectionManager() {
    stopReceiving = true;
    listeningThread.join();
}

bool ConnectionManager::sendMsg(Msg msg) {
    return _sendingInterface->sendMsg(msg);
}

void ConnectionManager::registerListener(ConnectionManager::ListenerId listenerId, MsgListener &&listener) {
    _listeners.insert(std::make_pair(listenerId, listener));
}

void ConnectionManager::receivingLoop() {
    while (!stopReceiving) {
        Msg msg = _receivingInterface->receiveMsg();
        if (!msg.empty()) {
            merger.addPart(msg);
            sendMsgIfReady();
        } else {
            std::this_thread::sleep_for(std::chrono::microseconds(1000));
        }
    }
}

void ConnectionManager::sendMsgIfReady() {
    while (merger.isMsgReady()) {
        std::cout<<"Wiadomosc gotowa, przesylam...\n";
        auto readyMsg = merger.getMsg();
        if (_listeners.count(readyMsg[1]))
            _listeners[readyMsg[1]](readyMsg);
    }
}
