/*
* This file is connected to "Encoders.cpp"
* Owner: Marco Caliendo (MCal88)
* Contributors: Cameron Schwartzberg (BigBroccoli), and Andrew Barnes (abarnes6)
*/


#include "Encoders.h"
#include "PinDefinitions.h"

namespace encoders {
    void setupEncoder(uint8_t pin1, uint8_t pin2, Encoder& encoder) {
        encoder.write(0);
    }

    inline int32_t readEncoder(Encoder& encoder) {
        return encoder.read();
    }
    
    float getRPM(Encoder& encoder) {
        int32_t counts = readEncoder(encoder);
        return ((static_cast<float>(counts) / PPR) * 60.0f) / CV;
    }
}
