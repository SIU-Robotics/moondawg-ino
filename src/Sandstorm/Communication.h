#ifndef Communication_h
#define Communication_h


#include <ESP32Servo.h>
#include <Arduino.h>
#include <ESP32Encoder.h>

/*
* PinDefinitions.h: This holds all of the pin definitions that can then be used to output signals.
* Movement.h: This holds the classes and functions that allow the bot to operated.
* Camera.h: This holds the class and functions for the camera to be able to move.
*/

#include "PinDefinitions.h"
#include "Motors.h"
#include "Encoders.h"
#include "Communication.h"

namespace comm{
    void Process(char* tokens[], motors::Container motorContainer);
}

#endif //Communication_h
