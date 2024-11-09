/*
* Owner: Marco Caliendo (MCal88)
* Contributors: Cameron Schwartzberg (BigBroccoli), and Andrew Barnes (abarnes6)
*/

#ifndef Encoders_h
#define Encoders_h

#include <ESP32Encoder.h>
#include <Arduino.h>

namespace encoders {
    constexpr uint8_t PPR = 20;
    constexpr uint8_t CV = 4;

    struct Container {
        ESP32Encoder motor_encoder;
        volatile int32_t lastCount{0};
        volatile uint32_t lastReadTime{0};
    };

    void setupEncoder(uint8_t pin_1, uint8_t pin_2, ESP32Encoder &encoder);
    inline int32_t readEncoder(ESP32Encoder enc, int32_t& lastCount);
    float getRPM(ESP32Encoder& encoder, Container& container);
}

#endif // Encoders_h
