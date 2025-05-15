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

// Encoders are only used if USE_ENCODER_SYSTEM is defined
#ifdef USE_ENCODER_SYSTEM
#ifdef WROOM32
#include <ESP32Encoder.h>
#else
#include <Encoder.h>
#endif
#include "Encoders.h" // Contains functions for reading encoder values
#endif

namespace
{
    // Define constants
    constexpr uint8_t STOP = 90;             // Stop value for the motors
    constexpr uint8_t MAX_ARRAY_SIZE = 10;   // Maximum size for token array
    constexpr uint8_t MAX_INPUT_LENGTH = 50; // Maxium length for input string
    constexpr uint8_t DEFAULT_POS_TURN = 90;

    static motors::Container motorContainer{};
#ifdef USE_ENCODER_SYSTEM
// Fix initialization of encoder container
#ifdef WROOM32
    encoders::Container encoderContainer{}; // Default initialization
#else
    encoders::Container encoderContainer{}; // Default initialization
#endif

// Add declarations for encoder instances and tracking variables
#ifdef WROOM32
    ESP32Encoder fr_encoder, fl_encoder, rr_encoder, rl_encoder;
#else
    Encoder fr_encoder(0, 0); // Replace with actual pin numbers
    Encoder fl_encoder(0, 0); // Replace with actual pin numbers
    Encoder rr_encoder(0, 0); // Replace with actual pin numbers
    Encoder rl_encoder(0, 0); // Replace with actual pin numbers
#endif

    uint32_t millisBefore = 0;
#endif
}

void setup()
{
#ifdef USE_ENCODER_SYSTEM
    comm::i2cSetup(motorContainer, encoderContainer);
#else
    comm::i2cSetup(motorContainer);
#endif
    Serial.begin(115200);

#ifdef USE_DRIVE_SYSTEM
    motors::Setup(pin::DRIVE_MOTOR, motorContainer.driveMotor, STOP);
#endif

#ifdef USE_TURN_SYSTEM

    motors::Setup(pin::TURN_MOTOR_FL, motorContainer.turnMotorFL, DEFAULT_POS_TURN);
    motors::Setup(pin::TURN_MOTOR_FR, motorContainer.turnMotorFR, DEFAULT_POS_TURN);
    motors::Setup(pin::TURN_MOTOR_RL, motorContainer.turnMotorRL, DEFAULT_POS_TURN);
    motors::Setup(pin::TURN_MOTOR_RR, motorContainer.turnMotorRR, DEFAULT_POS_TURN);
#endif

#ifdef USE_DIGGING_SYSTEM
    motors::Setup(pin::DIGGING_MOTOR, motorContainer.digMotor, STOP);
    motors::Setup(pin::DIGGING_RACTUATOR, motorContainer.rActuator, STOP);
    motors::Setup(pin::DIGGING_LACTUATOR, motorContainer.lActuator, STOP);
#endif

#ifdef USE_DEPOSIT_SYSTEM
    // Deposit system
    motors::Setup(pin::DEPOSIT_MOTOR, motorContainer.auger, STOP);
    motors::Setup(pin::DEPOSIT_VIBRATOR, motorContainer.vibrator, STOP);
#endif

#ifdef USE_CAMERA_SYSTEM
    // Set up camera servos
    // Note: These are initializaed to sepcific positions other than STOP
    motors::Setup(pin::HORIZONTAL_SERVO, motorContainer.horizontalServo, 180);
    motors::Setup(pin::VERTICAL_SERVO, motorContainer.verticalServo, 90);
#endif

#ifdef USE_ENCODER_SYSTEM
    // Set up encoders
    encoders::setupEncoder(pin::ENCODER_PIN1, pin::ENCODER_PIN2, encoderContainer.motor_encoder);
#endif
}

void loop()
{

#ifdef USE_ENCODER_SYSTEM
    // Current time for RPM calculations
    static uint32_t millisBefore = millis();

    if (millis() - millisBefore > 100) // Update every 100ms for smoother readings
    {
        // Read encoders and update RPM and direction for each wheel
        encoderContainer.rpm = encoders::getRPM(encoderContainer.motor_encoder,
                                                encoderContainer.lastCount,
                                                encoderContainer.lastReadTime,
                                                encoderContainer.direction);

        // Debug output (optional)
        Serial.print("Motor RPM: ");
        Serial.print(encoderContainer.rpm);
        Serial.print(", Direction: ");
        switch (encoderContainer.direction)
        {
        case encoders::Direction::FORWARD:
            Serial.println("FORWARD");
            break;
        case encoders::Direction::BACKWARD:
            Serial.println("BACKWARD");
            break;
        case encoders::Direction::STOPPED:
            Serial.println("STOPPED");
            break;
        }

        millisBefore = millis();
    }
#endif
}
