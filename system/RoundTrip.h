#pragma once

#include "UARTInterface.h"
#include "I2cInterface.h"
#include "ConnectionManager.h"

class RoundTrip {
public:
    RoundTrip();

    bool sendMsg(const std::vector<uint8_t> &msg);

    void receiveMsg(const std::vector<uint8_t> &msg);
    bool testResult() const;

private:
    UARTInterface uart;
    I2cInterface i2c;
    ConnectionManager connectionManager;
    uint8_t msgSent;
    uint8_t msgReceived;
};
