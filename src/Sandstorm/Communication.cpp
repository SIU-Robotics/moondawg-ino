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

    // Forward declarations - must be at the top
    static void receiveEvent(int numBytes);
    static void processI2CData();
    static inline void processCommand(const uint8_t cmd, const int param1, const int param2, motors::Container& motorContainer);

    // Function implementations
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

    void i2cSetup(motors::Container& container) {
        g_motorContainer = &container;
        Wire.begin(pin::I2C_ADDRESS, pin::I2C_SDA, pin::I2C_SCL);
        Wire.onReceive(receiveEvent);  // Now receiveEvent is properly declared before use
    }


    static void processI2C() {
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
            processI2C();
            return true;
        }
        return false;
    }

    void clearNewDataFlag() {
        g_newData = false;
        memset(g_inputBuffer, 0, MAX_INPUT_LENGTH + 1);
    }

    static inline void processCommand(const uint8_t cmd, const int param1, const int param2, motors::Container& motorContainer) {
        switch (cmd) {
            #ifdef USE_DRIVE_SYSTEM
                case MOVEMENT:
                    motors::Set(motorContainer.driveMotor, param1);
                    break;
            #endif

            #ifdef USE_TURN_SYSTEM
                case TURN:
                    switch (param2){
                        case '1': // FL
                            motors::Set(motorContainer.turnMotorFL, param1);
                            break;
                        case '2': // FR
                            motors::Set(motorContainer.turnMotorFR, param1);
                            break;
                        case '3': // RL
                            motors::Set(motorContainer.turnMotorRL, param1);
                            break;
                        case '4': // RR
                            motors::Set(motorContainer.turnMotorRR, param1);
                            break;
                    }
                    break;
            #endif

            #ifdef USE_DIGGING_SYSTEM
                case DIGBELT:
                    param1 ? motors::Set(motorContainer.digMotor, param2) : motors::Stop(motorContainer.digMotor);
                    break;
                case DIGACT:
                    if (param1) {
                        param2 == 'r' ? motors::Forward(motorContainer.actuator) :
                        param2 == 'l' ? motors::Backward(motorContainer.actuator) : void();
                    } 
                    else {
                        motors::Stop(motorContainer.actuator);
                    }
                    break;
            #endif
            
            #ifdef USE_DEPOSIT_SYSTEM
                case DEPOSITAUGER:
                    if (param1) {
                        param2 == 'f' ? motors::Forward(motorContainer.auger) :
                        param2 == 'b' ? motors::Backward(motorContainer.auger) : void();
                    } 
                    else {
                        motors::Stop(motorContainer.auger);
                    }
                    break;
                case VIBRATOR:
                    param1 && param2 == 'v' ? motors::Forward(motorContainer.vibrator) : motors::Stop(motorContainer.vibrator);
                    break;
            #endif
                
            #ifdef USE_CAMERA_SYSTEM
                case HORIZONTAL:
                    if (param1) motors::Set(motorContainer.horizontalServo, param2);
                    break;
                case VERTICAL:
                    if (param1) motors::Set(motorContainer.verticalServo, param2);
                    break;
                case ARM:
                    if (param1) motors::Set(motorContainer.armServo, param2);
                    break;
            #endif

                default:
                    break;
        }
    }

    
    void Process(char* tokens[], motors::Container& motorContainer) {
        if (tokens[0] == nullptr || tokens[1] == nullptr) {
            return;
        }

        const uint8_t cmd = static_cast<uint8_t>(tokens[0][0]); 
        const int param1 = atoi(tokens[1]);
        int param2 = 0;

        if (tokens[2] != nullptr) {
            bool isNumericParam = false;
            #ifdef USE_DRIVE_SYSTEM
                isNumericParam |= (cmd == MOVEMENT);
            #endif
            #ifdef USE_TURN_SYSTEM
                isNumericParam |= (cmd == TURN);
            #endif
            #ifdef USE_DIGGING_SYSTEM
                isNumericParam |= (cmd == DIGBELT);
            #endif
            #ifdef USE_CAMERA_SYSTEM
                isNumericParam |= (cmd == HORIZONTAL || cmd == VERTICAL || cmd == ARM);
            #endif

            param2 = isNumericParam ? atoi(tokens[2]) : static_cast<int>(tokens[2][0]);
        }

        processCommand(cmd, param1, param2, motorContainer);
    }
    
}