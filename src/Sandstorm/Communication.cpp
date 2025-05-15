/*
 * Communication.cpp - Implementation file for handling communication between the RPi and the microcontroller
 * for the Sandstorm 2024 Lunabotics bot.
 *
 * This file implements the communication protocol and processing functions.
 *
 * Owner: Cameron Schwartzberg (BigBroccoli)
 * Contributors: Andrew Barnes (abarnes6), Marco Caliendo (MCal88)
 * Date Created: 2/18/2024
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

    static inline void processCommand(const int motor, const int value)
    {
#ifdef USE_DRIVE_SYSTEM
        switch (motor)
        {
        case 1: // FL
            motors::Set(g_motorContainer->driveMotorFL, value);
            break;
        case 2: // FR
            motors::Set(g_motorContainer->driveMotorFR, value);
            break;
        case 3: // RL
            motors::Set(g_motorContainer->driveMotorRL, value);
            break;
        case 4: // RR
            motors::Set(g_motorContainer->driveMotorRR, value);
            break;
        case 5: // FL Servo
            motors::Set(g_motorContainer->turnMotorFL, value);
            break;
        case 6: // FR Servo
            motors::Set(g_motorContainer->turnMotorFR, value);
            break;
        case 7: // RL Servo
            motors::Set(g_motorContainer->turnMotorRL, value);
            break;
        case 8: // RR Servo
            motors::Set(g_motorContainer->turnMotorRR, value);
            break;
        default:
            break;
        }
#endif

#ifdef USE_EXCAVATION_SYSTEM
        switch (motor)
        {
        case 1: // Belt
            motors::Set(g_motorContainer->beltMotor, value);
            break;
        case 2: // Auger
            motors::Set(g_motorContainer->augerMotor, value);
            break;
        case 3: // Left Actuator
            motors::Set(g_motorContainer->lActuator, value);
            break;
        case 4: // Right Actuator
            motors::Set(g_motorContainer->rActuator, value);
            break;
        case 5: // Vibe motor
            motors::Set(g_motorContainer->vibeMotor, value);
            break;
        default:
            break;
        }
#endif
    }

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
            int param1 = 0;
            int param2 = 0;

            // Read first byte as command
            if (Wire.available())
            {
                param1 = Wire.read();
            }

            // Read second byte as param1 if available
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
}