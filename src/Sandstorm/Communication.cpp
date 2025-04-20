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
            uint8_t i = 0;
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
        default:
            break;
        }
#endif

#ifdef USE_DIGGING_SYSTEM
        motors::Set(motorContainer.digMotor, param2);
        motors::Stop(motorContainer.digMotor);
        motors::Forward(motorContainer.actuator);
        motors::Backward(motorContainer.actuator);
        motors::Stop(motorContainer.actuator);
#endif

#ifdef USE_DEPOSIT_SYSTEM

        motors::Forward(motorContainer.auger);
        motors::Backward(motorContainer.auger);
        motors::Stop(motorContainer.auger);
        motors::Forward(motorContainer.vibrator);
        motors::Stop(motorContainer.vibrator);
#endif

#ifdef USE_CAMERA_SYSTEM
        motors::Set(motorContainer.horizontalServo, param2);
        motors::Set(motorContainer.verticalServo, param2);
        motors::Set(motorContainer.armServo, param2);
#endif
    }
}