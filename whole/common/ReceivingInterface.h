#pragma once

#include <functional>
#include "CommonTypes.h"

class ReceivingInterface {
public:
    virtual ~ReceivingInterface() {}

    virtual Msg receiveMsg() = 0;
};
