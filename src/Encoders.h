/*
* Owner: Marco Caliendo (MCal88)
* Contributors: Marco Caliendo (MCal88)
*/

#ifndef Encoders_h
#define Encoders_h

#include <ESP32Encoder.h>
#include <Arduino.h>

int readEncoder(ESP32Encoder enc);
float getRPM(ESP32Encoder e);

#endif // Encoders_h
