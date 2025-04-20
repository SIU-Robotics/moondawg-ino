/*
 * Communication.h - Header file for handling communication between the RPi and the microcontroller
 * for the Sandstorm 2024 Lunabotics bot.
 *
 * This file defines the communication protocol and preocession functions.
 *
 * Owner: Cameron Schwartzberg (BigBroccoli)
 * Contributors: Andrew Barnes (abarnes6)
 * Date Created: 10/9/2024
 */

#ifndef Communication_h
#define Communication_h

// Include custom header files
#include <Wire.h>           // Required for I2C communication
#include "PinDefinitions.h" // Holds all of the pin definitions for output signals
#include "Motors.h"         // Contains motor-related functions

// Define a namespace 'comm' to encapsulate all communication functions
namespace comm
{
    // Constants
    constexpr uint8_t MAX_INPUT_LENGTH = 50;
    constexpr uint8_t MAX_ARRAY_SIZE = 10;

    void i2cSetup(motors::Container &container);
    static void processCommand(int param, int param2);
}

#endif // Communication_h
