#pragma once

#include <queue>
#include <ostream>
#include "CommonTypes.h"

class MsgMerger {
public:
    void addPart(const Msg &msg);

    bool isMsgReady() const;

    Msg getMsg();

private:
    bool isMsgReady(const Msg &msg) const;

    void addReadyMsgs();

    Msg currentMsg;
    std::queue<Msg> readyMsgs;
};

