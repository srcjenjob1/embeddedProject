#include "I2cInterface.h"
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <string>
#include <linux/i2c-dev.h>
#include <stdexcept>
#include <chrono>

I2cInterface::I2cInterface() {
    std::string devicePath = "/dev/i2c-1";
    int remoteDevAddr = 0x8;

    if ((deviceFd = open(devicePath.c_str(), O_RDWR)) < 0) {
        throw std::runtime_error("Failed to open the i2c bus");
    }

    if (ioctl(deviceFd, I2C_SLAVE, remoteDevAddr) < 0) {
        throw std::runtime_error("Failed to acquire bus access and/or talk to slave.");
    }
}

bool I2cInterface::sendMsg(Msg msg) {
    uint16_t delay = 100;
    while (write(deviceFd, &msg[0], msg.size()) != msg.size()) {
        //sleep and try again
        usleep(delay);
        delay += 100;
    }
    return true;
}

I2cInterface::~I2cInterface() {
    close(deviceFd);
}
