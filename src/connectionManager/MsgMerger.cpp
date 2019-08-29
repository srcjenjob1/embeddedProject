#include <stdexcept>
#include "MsgMerger.h"

void MsgMerger::addPart(const Msg &msg) {
    currentMsg.insert(currentMsg.end(), msg.begin(), msg.end());
    if (isMsgReady(currentMsg)) {
        addReadyMsgs();
    }
}

bool MsgMerger::isMsgReady() const {
    return !readyMsgs.empty();
}

Msg MsgMerger::getMsg() {
    if (readyMsgs.empty()) throw std::underflow_error("Empty msg queue");
    auto result = readyMsgs.front();
    readyMsgs.pop();
    return result;
}

bool MsgMerger::isMsgReady(const Msg &msg) const {
    return (!msg.empty() && (msg.size() >= msg[0]));
}

void MsgMerger::addReadyMsgs() {
    do {
        readyMsgs.push(Msg(currentMsg.begin(), currentMsg.begin() + currentMsg[0]));
        currentMsg = Msg(currentMsg.begin() + currentMsg[0], currentMsg.end());
    } while (isMsgReady(currentMsg));
}

