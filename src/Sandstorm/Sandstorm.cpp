/*
* This Arduino code is for Sandstorm the 2024 Lunabotics bot.
* The code has elements of the 2023 MoonDawg rover. However, has be heavily modified to abstract functions, use the Servo Library for control, 
* and use Serial for RPi -> Arduino communication.
* This main file is uploaded to the Arduino and will take the commands from the RPi and proccesses that into function calls.
* Owner: Cameron Schwartzberg
* Contributors: Marco Caliendo, Andrew Barnes, Mitchell Wettig, Jared Hillyer, and Joshua Greuel
* Date Created: 2/18/2024
*/

// Call all libraries
#include <ESP32Servo.h>
#include <Arduino.h>
#include <ESP32Encoder.h>

/*
* PinDefinitions.h: This holds all of the pin definitions that can then be used to output signals.
* Movement.h: This holds the classes and functions that allow the bot to operated.
* Camera.h: This holds the class and functions for the camera to be able to move.
*/

#include "PinDefinitions.h"
#include "Motors.h"
#include "Encoders.h"
#include "Communication.h"

constexpr uint8_t STOP = 90;

// Creates the max array size and input length which is used to 
constexpr uint8_t MAX_ARRAY_SIZE = 10;
constexpr uint8_t MAX_INPUT_LENGTH = 50;


// Variable for keeping track of elapsed time : used for getting rpm of motors
unsigned long millisBefore = 0;


motors::Container motorContainer{};
encoders::Container encoderContainer{};


void setup() {
    // For the serial communication from RPi to Arduino
    Serial.begin(9600);
    
    // Setting up the motors in Movement.h/cpp
    motors::Setup(pin::DIGGING_MOTOR, motorContainer.digMotor, STOP);
    motors::Setup(pin::DIGGING_ACTUATOR, motorContainer.actuator, STOP);
    motors::Setup(pin::DEPOSIT_MOTOR, motorContainer.auger, STOP);
    motors::Setup(pin::DEPOSIT_VIBRATOR, motorContainer.vibrator, STOP);
    motors::Setup(pin::LEFT_MOTOR, motorContainer.driveMotor1, STOP);
    motors::Setup(pin::RIGHT_MOTOR, motorContainer.driveMotor2, STOP);

    // Setting up the camera servos in Camera.h/cpp
    motors::Setup(pin::HORIZONTAL_SERVO, motorContainer.horizontalServo, 180);
    motors::Setup(pin::VERTICAL_SERVO, motorContainer.verticalServo, 90);
    motors::Setup(pin::ARM_SERVO, motorContainer.armServo, 0);

    // Setting up the encoders in Encoders.h/cpp
    encoders::setupEncoder(pin::FRONT_LEFT_WHEEL_ENCODER_PIN1, pin::FRONT_LEFT_WHEEL_ENCODER_PIN2, encoderContainer.fl_encoder);
}

void loop() {

    // This parses the data sent from the RPi
    if (Serial.available() > 0) {
        char inputBuffer[MAX_INPUT_LENGTH + 1] = {0}; // +1 for null terminator

        // Read bytes directly into the buffer
        int bytesRead = Serial.readBytesUntil('\n', inputBuffer, MAX_INPUT_LENGTH);
        inputBuffer[bytesRead] = '\0'; // Add null terminator

        char* tokens[MAX_ARRAY_SIZE] = {nullptr};

        int numCount = 0;
        char *token = strtok(inputBuffer, ",");

        while (token != NULL && numCount < MAX_ARRAY_SIZE) {
            tokens[numCount++] = token;
            token = strtok(NULL, ",");
        }

        comm::Process(tokens, motorContainer);
    }

    // Encoder Code
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


