#pragma once

#include <vector>
#include <cinttypes>
#include "SendingInterface.h"

class I2cInterface : public SendingInterface {
public:
    I2cInterface();

    virtual ~I2cInterface();

    bool sendMsg(Msg msg);

private:
    int deviceFd;
};
