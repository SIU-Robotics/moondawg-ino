/*
* Owner: Marco Caliendo (MCal88)
* Contributors: Marco Caliendo (MCal88)
*/

#ifndef Encoders_h
#define Encoders_h

#include <Encoder.h>
#include <Arduino.h>

int readEncoder(Encoder enc);
float getRPM(Encoder e);

#endif // Encoders_h
