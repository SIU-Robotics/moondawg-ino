/*
* This file is connected to "Encoders.cpp"
* Owner: Marco Caliendo (MCal88)
* Contributors: Marco Caliendo (MCal88)
*/

#include <Arduino.h>
#include <Encoder.h>
#include "PinDefinitions.h"

unsigned long millisBefore = 0;
long counts = 0;

// Pulse Per Revolution
int ppr = 600;
// Constant Variable for tuning the rpm function
constexpr uint8_t cv = 4;

int readEncoder(Encoder enc) {
    counts = enc.read();
    return counts;
}

float getRPM(Encoder e) {
    rpm = ((readEncoders(e) / ppr) * 60.0) / cv;
    return rpm;
}