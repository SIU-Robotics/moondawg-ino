/*
* Owner: Marco Caliendo (MCal88)
* Contributors: Marco Caliendo (MCal88)
*/

#ifndef Encoders_h
#define Encoders_h

#include <ESP32Encoder.h>
#include <Arduino.h>

// Define the encoder objects and attach the pins defined in "PinDefinitions"
extern ESP32Encoder fl_encoder;
extern ESP32Encoder fr_encoder;
extern ESP32Encoder rr_encoder;
extern ESP32Encoder rl_encoder;

void setupEncoder(uint8_t fl_pin_1, uint8_t fl_pin_2, uint8_t fr_pin_1, uint8_t fr_pin_2, uint8_t rl_pin_1, uint8_t rl_pin_2, uint8_t rr_pin_1, uint8_t rr_pin_2);
int readEncoder(ESP32Encoder enc);
float getRPM(ESP32Encoder e);

#endif // Encoders_h
