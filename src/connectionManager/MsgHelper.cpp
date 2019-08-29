#include <stdexcept>
#include "MsgHelper.h"


uint8_t MsgHelper::getValue(const Msg &msg) {
    return msg[3];
}

