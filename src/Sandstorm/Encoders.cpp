/*
* This file is connected to "Encoders.cpp"
* Owner: Marco Caliendo (MCal88)
* Contributors: Marco Caliendo (MCal88), Cameron Schwartzberg (BigBroccoli)
*/


#include "Encoders.h"
#include "PinDefinitions.h"

namespace encoders {
    //unsigned long millisBefore = 0;
    long counts = 0;
    float rpm = 0;

    // Pulse Per Revolution
    int ppr = 600;
    // Constant Variable for tuning the rpm function
    constexpr uint8_t cv = 4;

    void setupEncoder(uint8_t pin_1, uint8_t pin_2, ESP32Encoder &encoder) {
        encoder.attachFullQuad(pin_1, pin_2);
    }


    /*
    * Function must be called as often as possible in the main file
    * How we handle this may change if we decide to go with full interrupts for all encoders
    */
    int readEncoder(ESP32Encoder enc) {
        counts = enc.getCount();
        return counts;
    }

    /* 
    * For whatever reason there was a miss match between pulses per revolution 
    * read on the arduino vs. pulses per revolution labeled on the encoder.
    * This resulted in this function returning an rpm 4 times higher than in reality.
    * The variable cv in this function fixes the issue but may need to change to a 
    * different value if different encoders are used in the future.
    */
    float getRPM(ESP32Encoder e) {
        rpm = ((readEncoder(e) / ppr) * 60.0) / cv;
        return rpm;
    }
}
