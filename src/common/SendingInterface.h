#pragma once

#include <vector>
#include <cinttypes>
#include "CommonTypes.h"

class SendingInterface {
public:
    virtual ~SendingInterface() {}

    virtual bool sendMsg(Msg msg) = 0;
};
