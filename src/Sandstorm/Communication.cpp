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

namespace comm
{
    // Static variables with internal linkage
    static motors::Container *g_motorContainer = nullptr;
    static char g_inputBuffer[MAX_INPUT_LENGTH + 1] = {0};
    static volatile bool g_newData = false;

    // Forward declarations - must be at the top
    static void receiveEvent(int numBytes);
    static inline void processCommand(const int param1, const int param2);

    static void receiveEvent(int numBytes)
    {
        if (numBytes > MAX_INPUT_LENGTH)
        {
            numBytes = MAX_INPUT_LENGTH; // Prevent buffer overflow
        }

        // Single byte command
        if (numBytes == 1)
        {
            uint8_t cmd = Wire.read();
            processCommand(cmd, -1);
            return;
        }

        // Multi-byte command - reads as a block
        else if (numBytes > 1)
        {
            uint8_t cmd = 0;
            int param1 = 0;
            int param2 = 0;

            // Read first byte as command
            if (Wire.available())
            {
                cmd = Wire.read();
            }

            // Read second byte as param1 if available
            if (Wire.available())
            {
                param1 = Wire.read();
            }

            // Read third byte as param2 if available
            if (Wire.available())
            {
                param2 = Wire.read();
            }

            // Process the command with its parameters
            processCommand(param1, param2);

            // Discard any additional bytes
            while (Wire.available())
            {
                Wire.read();
            }
        }
    }

    void i2cSetup(motors::Container &container)
    {
        g_motorContainer = &container;

        // ESP32 specific I2C initialization
        Wire.onReceive(receiveEvent);

        // Configure ESP32 as I2C slave with specified address
        Wire.begin(pin::I2C_ADDRESS);
    }

    static inline void processCommand(const int param1, const int param2)
    {
#ifdef USE_DRIVE_SYSTEM
        motors::Set(g_motorContainer->driveMotor, param1);
#endif
#ifdef USE_TURN_SYSTEM
        switch (param1)
        {
        case 1: // FL
            motors::Set(g_motorContainer->turnMotorFL, param2);
            break;
        case 2: // FR
            motors::Set(g_motorContainer->turnMotorFR, param2);
            break;
        case 3: // RL
            motors::Set(g_motorContainer->turnMotorRL, param2);
            break;
        case 4: // RR
            motors::Set(g_motorContainer->turnMotorRR, param2);
            break;
        default:
            break;
        }
#endif

#ifdef USE_DIGGING_SYSTEM
        switch (param1)
        {
        case 1: // Belt speed
            motors::Set(g_motorContainer->digMotor, param2);
            break;
        case 2: // Raise or lower belt
            motors::Set(g_motorContainer->actuator, param2);
            break;
        }
#endif

#ifdef USE_DEPOSIT_SYSTEM
        switch (param1)
        {
        case 1: // Auger
            motors::Set(g_motorContainer->auger, param2);
            break;
        case 2: // Vibrator
            motors::Set(g_motorContainer->vibrator, param2);
            break;
        }
#endif

#ifdef USE_CAMERA_SYSTEM
        switch (param1)
        {
        case 1: // Horizontal servo
            motors::Set(g_motorContainer->horizontalServo, param2);
            break;
        case 2: // Vertical servo
            motors::Set(g_motorContainer->verticalServo, param2);
            break;
        case 3: // Arm servo
            motors::Set(g_motorContainer->armServo, param2);
            break;
        default:
            break;
        }
#endif
    }
}