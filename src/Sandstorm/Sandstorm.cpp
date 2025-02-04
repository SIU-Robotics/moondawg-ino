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
#include <Encoder.h>

// Include custom header files
#include "PinDefinitions.h" // Holds all of the pin definitions for output signals
#include "Motors.h"         // Contains motor-related functions
#include "Encoders.h"       // Contains functions for reading encoder values
#include "Communication.h"  // Contains function for parsing commands from the RPi

namespace {
    // Define constants
    constexpr uint8_t STOP = 90;                // Stop value for the motors
    constexpr uint8_t MAX_ARRAY_SIZE = 10;      // Maximum size for token array
    constexpr uint8_t MAX_INPUT_LENGTH = 50;    // Maxium length for input string
    constexpr uint8_t DEFAULT_POS_TURN = 90;

    static motors::Container motorContainer{};
    encoders::Container encoderContainer{Encoder(0, 0)};
}

void setup() {
    // For the i2c communication
    comm::i2cSetup(motorContainer);
    
    #ifdef USE_DRIVE_SYSTEM
        motors::Setup(pin::DRIVE_MOTOR, motorContainer.driveMotor, STOP);
    #endif

    #ifdef USE_TURN_SYSTEM
        motors::Setup(pin::TURN_MOTOR, motorContainer.turnMotor, DEFAULT_POS_TURN);
    #endif

    #ifdef USE_DIGGING_SYSTEM
        motors::Setup(pin::DIGGING_MOTOR, motorContainer.digMotor, STOP);
        motors::Setup(pin::DIGGING_ACTUATOR, motorContainer.actuator, STOP);
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
        motors::Setup(pin::ARM_SERVO, motorContainer.armServo, 0);
    #endif

    #ifdef USE_ENCODER_SYSTEM
        // Set up encoders
        encoders::setupEncoder(pin::ENCODER_PIN1, pin::ENCODER_PIN2, encoderContainer.motor_encoder);
    #endif
}

void loop() {
    if (comm::hasNewData()) {
        comm::clearNewDataFlag();
    }


    // Encoder reading code
    // readEncoder(fr_encoder);
    // readEncoder(fl_encoder);
    // readEncoder(rr_encoder);
    // readEncoder(rl_encoder);
    // if (millis() - millisBefore > 1000) {
    //     getRPM(fr_encoder);
    //     getRPM(fl_encoder);
    //     getRPM(rr_encoder);
    //     getRPM(rl_encoder);
    //     millisBefore = millis();
    // }
}


