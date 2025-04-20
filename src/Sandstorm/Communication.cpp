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
#include <Wire.h> // Explicitly include Wire.h for ESP32

namespace comm
{
    // Static variables with internal linkage
    static motors::Container *g_motorContainer = nullptr;
    static char g_inputBuffer[MAX_INPUT_LENGTH + 1] = {0};
    static volatile bool g_newData = false;

    // Forward declarations - must be at the top
    static void receiveEvent(int numBytes);
    static void processI2C(); // Changed from processI2CData to match implementation
    static inline void processCommand(const uint8_t cmd, const int param1, const int param2, motors::Container &motorContainer);

    // Function implementations
    static void receiveEvent(int numBytes)
    {
        if (numBytes > MAX_INPUT_LENGTH)
        {
            numBytes = MAX_INPUT_LENGTH; // Prevent buffer overflow
        }

        uint8_t i = 0;
        int cmd = 90;
        int cmd2 = 0;
        while (Wire.available() && i < numBytes)
        {
            char c = Wire.read();
            // g_inputBuffer[i++] = c;
            cmd = c;
        }
        processCommand(cmd, cmd2);
        // g_inputBuffer[i] = '\0';
        // g_newData = true;
        // processI2C();
    }

    void i2cSetup(motors::Container &container)
    {
        g_motorContainer = &container;

        // ESP32 specific I2C initialization
        Wire.onReceive(receiveEvent);

        // Configure ESP32 as I2C slave with specified address
        Wire.begin(pin::I2C_ADDRESS);
    }

    static void processI2C()
    {
        char *tokens[MAX_ARRAY_SIZE] = {nullptr};
        int numCount = 0;
        char *token = strtok(g_inputBuffer, ",");

        while (token != nullptr && numCount < MAX_ARRAY_SIZE)
        {
            tokens[numCount++] = token;
            token = strtok(nullptr, ",");
        }

        if (g_motorContainer != nullptr)
        {
            Process(tokens, numCount, *g_motorContainer);
        }
    }

    bool hasNewData()
    {
        if (g_newData)
        {
            processI2C();
            return true;
        }
        return false;
    }

    void clearNewDataFlag()
    {
        g_newData = false;
        memset(g_inputBuffer, 0, MAX_INPUT_LENGTH + 1);
    }

    void processCommand(const int param1, const int param2)
    {
#ifdef USE_DRIVE_SYSTEM
        motors::Set(g_motorContainer->driveMotor, param1);
#endif
#ifdef USE_TURN_SYSTEM
        switch (param2)
        {
        case 1: // FL
            motors::Set(motorContainer.turnMotorFL, param1);
            break;
        case 2: // FR
            motors::Set(motorContainer.turnMotorFR, param1);
            break;
        case 3: // RL
            motors::Set(motorContainer.turnMotorRL, param1);
            break;
        case 4: // RR
            motors::Set(motorContainer.turnMotorRR, param1);
            break;
        }
#endif

#ifdef USE_DIGGING_SYSTEM
        param1 ? motors::Set(motorContainer.digMotor, param2) : motors::Stop(motorContainer.digMotor);
    case DIGACT:
        if (param1)
        {
            param2 == 'r' ? motors::Forward(motorContainer.actuator) : param2 == 'l' ? motors::Backward(motorContainer.actuator)
                                                                                     : void();
        }
        else
        {
            motors::Stop(motorContainer.actuator);
        }
        break;
#endif

#ifdef USE_DEPOSIT_SYSTEM
        if (param1)
        {
            param2 == 'f' ? motors::Forward(motorContainer.auger) : param2 == 'b' ? motors::Backward(motorContainer.auger)
                                                                                  : void();
        }
        else
        {
            motors::Stop(motorContainer.auger);
        }
        param1 &&param2 == 'v' ? motors::Forward(motorContainer.vibrator) : motors::Stop(motorContainer.vibrator);
#endif

        // #ifdef USE_CAMERA_SYSTEM
        //     case HORIZONTAL:
        //         if (param1)
        //             motors::Set(motorContainer.horizontalServo, param2);
        //         break;
        //     case VERTICAL:
        //         if (param1)
        //             motors::Set(motorContainer.verticalServo, param2);
        //         break;
        //     case ARM:
        //         if (param1)
        //             motors::Set(motorContainer.armServo, param2);
        //         break;
        // #endif
    }

    void Process(char *tokens[], int token_count, motors::Container &motorContainer)
    {
        const int param1 = atoi(tokens[0]);
        int param2 = 0;
        if (token_count > 1)
        {
            param2 = atoi(tokens[1]);
        }
        processCommand(param1, param2);
    }
}