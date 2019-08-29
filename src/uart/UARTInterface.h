#pragma once

#include <vector>
#include <cinttypes>
#include <SerialPort.h>
#include <thread>
#include <list>
#include <fstream>
#include "ReceivingInterface.h"


class UARTInterface : public ReceivingInterface {
public:
    UARTInterface();

    virtual ~UARTInterface();

    Msg receiveMsg() override;

private:
    SerialPort serial_port;
};
