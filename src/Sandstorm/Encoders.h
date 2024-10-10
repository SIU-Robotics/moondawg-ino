/*
* Owner: Marco Caliendo (MCal88)
* Contributors: Marco Caliendo (MCal88), Cameron Schwartzberg (BigBroccoli)
*/

#ifndef Encoders_h
#define Encoders_h

#include <ESP32Encoder.h>
#include <Arduino.h>

namespace encoders {
    struct Container {
        ESP32Encoder fl_encoder;
        ESP32Encoder fr_encoder;
        ESP32Encoder rl_encoder;
        ESP32Encoder rr_encoder;
    };

    void setupEncoder(uint8_t fl_pin_1, uint8_t fl_pin_2, ESP32Encoder &encoder);
    int readEncoder(ESP32Encoder enc);
    float getRPM(ESP32Encoder e);
}

#endif // Encoders_h
