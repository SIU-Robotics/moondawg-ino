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
#include <Wire.h>               // Required for I2C communication
#include "PinDefinitions.h"     // Holds all of the pin definitions for output signals
#include "Motors.h"             // Contains motor-related functions
#include "Encoders.h"           // Contains functions for reading encoder values
#include "Communication.h"      // Contains function for parsing commands from the RPi

// Define a namespace 'comm' to encapsulate all communication functions
namespace comm{
    // Constants
    constexpr uint8_t MAX_INPUT_LENGTH = 50;
    constexpr uint8_t MAX_ARRAY_SIZE = 10;

    // Command characters
    constexpr char MOVEMENT = 'm';
    constexpr char DIGBELT = 'b';
    constexpr char DIGACT = 'g';
    constexpr char DEPOSITAUGER = 'd';
    constexpr char VIBRATOR = 'v';
    constexpr char HORIZONTAL = 'h';
    constexpr char VERTICAL = 'e';
    constexpr char ARM = 'a';

    void i2cSetup(motors::Container& container);
    void Process(char* tokens[], motors::Container& motorContainer);
    bool hasNewData();
    void clearNewDataFlag();
}

#endif //Communication_h
