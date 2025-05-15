/*
 * This the microcontroller code is for Sandstorm the 2024 Lunabotics bot.
 * This code is for esp-wrover-kit based ESP32 microcontrollers.
 * This main file holds the setup, loop functions, and string parsing for the bot.
 * Owner: Cameron Schwartzberg (BigBroccoli)
 * Contributors: Marco Caliendo (MCal88), Andrew Barnes (abarnes6), Mitchell Wettig, Jared Hillyer, and Joshua Greuel
 * Date Created: 2/18/2024
 */

// Include all necessary libraries
#include <ESP32Servo.h>
#include <Arduino.h>

// Include custom header files
#include "PinDefinitions.h" // Holds all of the pin definitions for output signals
#include "Motors.h"         // Contains motor-related functions
#include "Communication.h"  // Contains function for parsing commands from the RPi

namespace
{
    // Define constants
    constexpr uint8_t STOP = 90;             // Stop value for the motors
    constexpr uint8_t MAX_ARRAY_SIZE = 10;   // Maximum size for token array
    constexpr uint8_t MAX_INPUT_LENGTH = 50; // Maxium length for input string
    constexpr uint8_t DEFAULT_POS_TURN = 90;

    static motors::Container motorContainer{};
}

void setup()
{
    comm::i2cSetup(motorContainer);

#if defined(USE_DRIVE_SYSTEM)
    motors::Setup(pin::DRIVE_MOTOR_FL, motorContainer.driveMotorFL, STOP);
    motors::Setup(pin::DRIVE_MOTOR_FR, motorContainer.driveMotorFR, STOP);
    motors::Setup(pin::DRIVE_MOTOR_RL, motorContainer.driveMotorRL, STOP);
    motors::Setup(pin::DRIVE_MOTOR_RR, motorContainer.driveMotorRR, STOP);
    motors::Setup(pin::TURN_MOTOR_FL, motorContainer.turnMotorFL, DEFAULT_POS_TURN);
    motors::Setup(pin::TURN_MOTOR_FR, motorContainer.turnMotorFR, DEFAULT_POS_TURN);
    motors::Setup(pin::TURN_MOTOR_RL, motorContainer.turnMotorRL, DEFAULT_POS_TURN);
    motors::Setup(pin::TURN_MOTOR_RR, motorContainer.turnMotorRR, DEFAULT_POS_TURN);
#elif defined(USE_EXCAVATION_SYSTEM)
    motors::Setup(pin::BELT_MOTOR, motorContainer.beltMotor, STOP);
    motors::Setup(pin::AUGER_MOTOR, motorContainer.augerMotor, STOP);
    motors::Setup(pin::L_ACTUATOR, motorContainer.lActuator, STOP);
    motors::Setup(pin::R_ACTUATOR, motorContainer.rActuator, STOP);
    motors::Setup(pin::VIBRATION_MOTOR, motorContainer.vibeMotor, STOP);
#endif
}

void loop()
{
    // Process I2C communications from the Raspberry Pi
    // The actual processing happens in the I2C receive callback
    delay(10); // Small delay to prevent CPU hogging
}
