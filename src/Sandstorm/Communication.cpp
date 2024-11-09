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
    // Static variables with internal linkage
    static motors::Container* g_motorContainer = nullptr;
    static char g_inputBuffer[MAX_INPUT_LENGTH + 1] = {0};
    static volatile bool g_newData = false;

    // Internal function declarations
    static void receiveEvent(int numBytes);
    static void processI2CData();
    static inline void processCommand(const char cmd, const int param1, const int param2, motors::Container& motorContainer);

    void i2cSetup(motors::Container& container) {
        g_motorContainer = &container;
        Wire.begin(pin::I2C_ADDRESS, pin::I2C_SDA);
        Wire.onReceive(receiveEvent);
    }

    static void receiveEvent(int numBytes) {
        if (numBytes > MAX_INPUT_LENGTH) {
            numBytes = MAX_INPUT_LENGTH;  // Prevent buffer overflow
        }

        uint8_t i = 0;
        while (Wire.available() && i < numBytes) {
            char c = Wire.read();
            if (c == '\n' || c == '\0') break;
            g_inputBuffer[i++] = c;
        }
        g_inputBuffer[i] = '\0';
        g_newData = true;
    }

    static void process() {
        char* tokens[MAX_ARRAY_SIZE] = {nullptr};
        uint8_t numCount = 0;
        char* token = strtok(g_inputBuffer, ",");

        while (token != nullptr && numCount < MAX_ARRAY_SIZE) {
            tokens[numCount++] = token;
            token = strtok(nullptr, ",");
        }

        if (g_motorContainer != nullptr) {
            Process(tokens, *g_motorContainer);
        }
    }

    bool hasNewData() {
        if (g_newData) {
            process();
            return true;
        }
        return false;
    }

    void clearNewDataFlag() {
        g_newData = false;
        memset(g_inputBuffer, 0, MAX_INPUT_LENGTH + 1);
    }

    static inline void processCommand(const char cmd, const int param1, const int param2, motors::Container& motorContainer) {
        switch (cmd) {
            case MOVEMENT:
                motors::drive(param1, param2, motorContainer.driveMotor1, motorContainer.driveMotor2);
                break;
            case DIGBELT:
                param1 ? motors::Set(motorContainer.digMotor, param2) : motors::Stop(motorContainer.digMotor);
                break;
            case DIGACT:
                if (param1) {
                    if (param2 == 'r') motors::Forward(motorContainer.actuator);
                    else if (param2 == 'l') motors::Backward(motorContainer.actuator);
                } else {
                    motors::Stop(motorContainer.actuator);
                }
                break;
            case DEPOSITAUGER:
                if (param1) {
                    if (param2 == 'f') motors::Forward(motorContainer.auger);
                    else if (param2 == 'b') motors::Backward(motorContainer.auger);
                } else {
                    motors::Stop(motorContainer.auger);
                }
                break;
            case VIBRATOR:
                param1 && param2 == 'v' ? motors::Forward(motorContainer.vibrator) : motors::Stop(motorContainer.vibrator);
                break;
            case HORIZONTAL:
                if (param1) motors::Set(motorContainer.horizontalServo, param2);
                break;
            case VERTICAL:
                if (param1) motors::Set(motorContainer.verticalServo, param2);
                break;
            case ARM:
                if (param1) motors::Set(motorContainer.armServo, param2);
                break;
            default:
                break;
        }
    }

    void Process(char* tokens[], motors::Container& motorContainer) {
        if (tokens[0] == nullptr || tokens[1] == nullptr) {
            return;
        }

        const char cmd = tokens[0][0];
        const int param1 = atoi(tokens[1]);
        int param2 = 0;

        if (tokens[2] != nullptr) {
            param2 = (cmd == MOVEMENT || cmd == DIGBELT || cmd == HORIZONTAL || 
                     cmd == VERTICAL || cmd == ARM) ? atoi(tokens[2]) : 
                     static_cast<int>(tokens[2][0]);
        }

        processCommand(cmd, param1, param2, motorContainer);
    }
    
}