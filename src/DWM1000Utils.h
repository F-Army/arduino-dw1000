#pragma once

#include "Arduino.h"

namespace DWM1000Utils {
    boolean getBit(byte data[], uint16_t n, uint16_t bit);
    void setBit(byte data[], uint16_t n, uint16_t bit, boolean val);
    void writeValueToBytes(byte data[], int32_t val, uint16_t n);
}

