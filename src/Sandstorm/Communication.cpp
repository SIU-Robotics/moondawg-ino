/*
 * Communication.cpp - Implementation file for handling communication between the RPi and the microcontroller
 * for the Sandstorm 2024 Lunabotics bot.
 *
 * This file implements the communication protocol and preocession functions.
 *
 * Owner: Cameron Schwartzberg (BigBroccoli)
 * Contributors: Andrew Barnes (abarnes6), Marco Caliendo (MCal88)
 * Date Created: 10/9/2024
 */

#include "Communication.h"

namespace comm
{
    // Static variables with internal linkage
    static motors::Container *g_motorContainer = nullptr;

#ifdef USE_ENCODER_SYSTEM
    static encoders::Container *g_encoderContainer = nullptr;
    static uint8_t g_responseBuffer[4] = {0};
#endif

    static char g_inputBuffer[MAX_INPUT_LENGTH + 1] = {0};
    static volatile bool g_newData = false;

    // Forward declarations - must be at the top
    static void receiveEvent(int numBytes);
#ifdef USE_ENCODER_SYSTEM
    void requestEvent();
#endif

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
            motors::Set(g_motorContainer->rActuator, param2);
            motors::Set(g_motorContainer->lActuator, param2);
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

#ifdef USE_ENCODER_SYSTEM
    void requestEvent()
    {
        if (!g_encoderContainer) return;
        
        // Get the integer part of RPM (up to 255) and the fractional part
        uint8_t rpmInt = static_cast<uint8_t>(std::min(g_encoderContainer->rpm, 255.0f));
        uint8_t rpmFrac = static_cast<uint8_t>((g_encoderContainer->rpm - rpmInt) * 100);
        
        // Get direction as uint8_t
        uint8_t direction = encoders::directionToUint8(g_encoderContainer->direction);
        
        // Fill the response buffer
        g_responseBuffer[0] = rpmInt;
        g_responseBuffer[1] = rpmFrac;
        g_responseBuffer[2] = direction;
        
        // Simple checksum
        g_responseBuffer[3] = rpmInt ^ rpmFrac ^ direction;
        
        // Send the prepared data
        Wire.write(g_responseBuffer, sizeof(g_responseBuffer));
    }

    void i2cSetup(motors::Container &container, encoders::Container &encoderContainer)
    {
        g_motorContainer = &container;
        g_encoderContainer = &encoderContainer;

        // ESP32 specific I2C initialization
        Wire.onReceive(receiveEvent);
        Wire.onRequest(requestEvent);

        // Configure ESP32 as I2C slave with specified address
        Wire.begin(pin::I2C_ADDRESS);
    }
#else
    void i2cSetup(motors::Container &container)
    {
        g_motorContainer = &container;

        // ESP32 specific I2C initialization
        Wire.onReceive(receiveEvent);

        // Configure ESP32 as I2C slave with specified address
        Wire.begin(pin::I2C_ADDRESS);
    }
#endif
}