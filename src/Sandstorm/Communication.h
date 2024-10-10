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
#include "PinDefinitions.h"     // Holds all of the pin definitions for output signals
#include "Motors.h"             // Contains motor-related functions
#include "Encoders.h"           // Contains functions for reading encoder values
#include "Communication.h"      // Contains function for parsing commands from the RPi

// Define a namespace 'comm' to encapsulate all communication functions
namespace comm{
    /*
    * Process function declaration
    * 
    * @param tokens An array of char pointers containing the parsed command tokens
    * @param motorContainer A struct containing all of the motor objects
    * 
    * This function interprets and executes commands received from the RPi
    * via serial communication. Allowing the RPi to communicate with the microcontroller
    */
    void Process(char* tokens[], motors::Container motorContainer);
}

#endif //Communication_h
