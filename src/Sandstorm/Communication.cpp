/*
* Communication.cpp - Implementation file for handling communication between the RPi and the microcontroller
* for the Sandstorm 2024 Lunabotics bot.
* 
* This file implements the communication protocol and preocession functions.
*
* Owner: Cameron Schwartzberg (BigBroccoli)
* Contributors: Andrew Barnes (abarnes6)
* Date Created: 10/9/2024
*/

#include "Communication.h"

namespace comm {
    // Static variables
    static motors::Container* g_motorContainer = nullptr;
    static char inputBuffer[MAX_INPUT_LENGTH + 1] = {0};
    static volatile bool newData = false;

    // Internal function declarations
    static void receiveEvent(int numBytes);
    static void processI2CData();

    void i2cSetup(motors::Container& container) {
        g_motorContainer = &container;
        Wire.begin(pin::I2C_ADDRESS, pin::I2C_SDA);
        Wire.onReceive(receiveEvent);
    }

    static void receiveEvent(int numBytes) {
        int i = 0;
        while (Wire.available() && i < MAX_INPUT_LENGTH) {
            char c = Wire.read();
            if (c == '\n' || c == '\0') {
                inputBuffer[i] = '\0';
                newData = true;
                break;
            }
            inputBuffer[i++] = c;
        }
        inputBuffer[i] = '\0';
        newData = true;
    }

    static void processI2CData() {
        char* tokens[MAX_ARRAY_SIZE] = {nullptr};
        int numCount = 0;
        char* token = strtok(inputBuffer, ",");

        while (token != NULL && numCount < MAX_ARRAY_SIZE) {
            tokens[numCount++] = token;
            token = strtok(NULL, ",");
        }

        if (g_motorContainer != nullptr) {
            Process(tokens, *g_motorContainer);
        }
    }

    bool hasNewData() {
        if (newData) {
            processI2CData();
            return true;
        }
        return false;
    }

    void clearNewDataFlag() {
        newData = false;
        memset(inputBuffer, 0, MAX_INPUT_LENGTH + 1);
    }
    /*
    * Process function implementation
    *
    * This function interprets commands sent the RPi and executes the corresponding functions.
    * Using a switch statement to determine which function to call based on the command character.
    * 
    * @param tokens An array of char pointers containing the parsed command tokens
    * @param motorContainer A struct containing all of the motor objects
    */
    void Process(char* tokens[], motors::Container& motorContainer) {
        // Check if at least two tokens are present
        if (tokens[0] == nullptr || tokens[1] == nullptr) {
            return;
        }

        char cmd = tokens[0][0];
        int param1 = atoi(tokens[1]);
        int param2;

        // Parse param2 if it exists
        if (tokens[2] != nullptr) {
            if (cmd == MOVEMENT || cmd == DIGBELT || cmd == HORIZONTAL || cmd == VERTICAL || cmd == ARM) {
                param2 = atoi(tokens[2]);
            }
            else {
                param2 = (int)tokens[2][0];
            }
        }

        // Process the command
        switch (cmd) {
            case MOVEMENT:
                motors::drive(param1, param2, motorContainer.driveMotor1, motorContainer.driveMotor2);
                break;
            case DIGBELT:
                if (param1) {
                    motors::Set(motorContainer.digMotor, param2);
                }
                else {
                    motors::Stop(motorContainer.digMotor);
                }
                break;
            case DIGACT:
                if (param1) {
                    if (param2 == 'r')
                    {
                        motors::Forward(motorContainer.actuator);
                    }
                    else if (param2 == 'l')
                    {
                        motors::Backward(motorContainer.actuator);
                    }                
                }
                else {
                    motors::Stop(motorContainer.actuator);
                }
                break;
            case DEPOSITAUGER:
                if (param1) {
                    if (param2 == 'f') {
                        motors::Forward(motorContainer.auger);
                    }
                    else if (param2 == 'b')
                    {
                        motors::Backward(motorContainer.auger);
                    }
                    
                }
                else {
                    motors::Stop(motorContainer.auger);
                }
                break;
            case VIBRATOR:
                if (param1) {
                    if (param2 == 'v'){
                        motors::Forward(motorContainer.vibrator);
                    }
                }
                else {
                    motors::Stop(motorContainer.vibrator);
                }
                break;
            case HORIZONTAL:
                if (param1) {
                    motors::Set(motorContainer.horizontalServo, param2); // This is the function that will be called to move the horizontal servo
                }
                break;
            case VERTICAL:
                if (param1) {
                    motors::Set(motorContainer.verticalServo, param2); // This is the function that will be called to move the vertical servo
                }
                break;
            case ARM:
                if (param1) {
                    motors::Set(motorContainer.armServo, param2); // This is the function that will be called to move the arm servo
                }
                break;
            default:
                break;
        }
    }
}