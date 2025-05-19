/*
 * Communication.cpp - Implementation file for handling communication between the RPi and the microcontroller
 * for the Sandstorm 2024 Lunabotics bot.
 *
 * This file implements the communication protocol and processing functions.
 *
 * Owner: Cameron Schwartzberg (BigBroccoli)
 * Contributors: Andrew Barnes (abarnes6), Marco Caliendo (MCal88)
 * Date Created: 2/18/2024
 * Last Updated: May 16, 2025 - Switched from I2C to Serial communication
 */

#include "Communication.h"

namespace comm
{
    // Static variables with internal linkage
    static motors::Container *g_motorContainer = nullptr;

    static char g_inputBuffer[MAX_INPUT_LENGTH + 1] = {0};
    static uint8_t g_bufferIndex = 0;
    static volatile bool g_newData = false;

    static inline void processCommand(const int motor, const int value)
    {
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
        case 9: // Belt
            motors::Set(g_motorContainer->beltMotor, value);
            break;
        case 10: // Auger
            motors::Set(g_motorContainer->augerMotor, value);
            break;
        case 11: // Left Actuator
            motors::Set(g_motorContainer->lActuator, value);
            break;
        case 12: // Right Actuator
            motors::Set(g_motorContainer->rActuator, value);
            break;
        case 13: // Vibe motor
            digitalWrite(pin::VIBRATION_MOTOR, value > 90 ? HIGH : LOW);
            break;
        case 14: // Camera Yaw
            motors::Set(g_motorContainer->cameraYaw, value);
            break;
        case 15: // Camera Pitch
            motors::Set(g_motorContainer->cameraPitch, value);
            break;
        default:
            break;
        }
    }

    // Function to process incoming serial data
    void serialLoop()
    {
        while (Serial.available() > 0)
        {
            char inChar = (char)Serial.read();

            // If newline or carriage return is received, process the command
            if (inChar == '\n' || inChar == '\r')
            {
                if (g_bufferIndex > 0) // Only process if we have data
                {
                    g_inputBuffer[g_bufferIndex] = '\0'; // Null terminate

                    // Parse the command - format: <motor>,<value>
                    char *token = strtok(g_inputBuffer, ",");
                    if (token != nullptr)
                    {
                        int motor = atoi(token);
                        token = strtok(nullptr, ",");

                        if (token != nullptr)
                        {
                            int value = atoi(token);
                            processCommand(motor, value);
                        }
                        else
                        {
                            // Single parameter command
                            processCommand(motor, -1);
                        }
                    }

                    // Reset buffer for next command
                    g_bufferIndex = 0;
                }
            }
            else if (g_bufferIndex < MAX_INPUT_LENGTH)
            {
                // Add character to buffer
                g_inputBuffer[g_bufferIndex++] = inChar;
            }
        }
    }

    void serialSetup(motors::Container &container)
    {
        g_motorContainer = &container;

        // Initialize Serial communication
        Serial.begin(115200); // Match the baud rate in platformio.ini
        Serial.println("Serial communication initialized");
    }
}