#include "UARTInterface.h"

#include <cstring>
#include <iostream>
#include <unistd.h>
#include <stdexcept>


UARTInterface::UARTInterface() :
        serial_port("/dev/ttyACM0") {

    try {
        serial_port.Open(SerialPort::BAUD_9600);
    }
    catch (const SerialPort::OpenFailed &) {
        throw std::runtime_error("The serial port did not open correctly.");
    }
}

UARTInterface::~UARTInterface() {
    serial_port.Close();
}

Msg UARTInterface::receiveMsg() {
    if (!serial_port.IsDataAvailable()) {
        return {};
    }

    SerialPort::DataBuffer read_buffer;

    try {
        serial_port.Read(read_buffer, 0, 0);
    }
    catch (std::exception &ex) {
        std::cerr << "some error occurred:" << ex.what() << "\n";
    }
    return read_buffer;
}
