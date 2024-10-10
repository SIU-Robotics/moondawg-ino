/*
* Motors.h - Header file for handling motor control for the Sandstorm 2024 Lunabotics bot.
*
* This file defines the structure and functions for controlling various motors and servos
* used in the bot's operation.
*
* Owner: Cameron Schwartzberg (BigBroccoli)
* Contributors: Marco Caliendo (MCal88), Andrew Barnes (abarnes6), and Mitchell Wettig
* Date Created: 2/18/2024
*/

#ifndef Motors_h
#define Motors_h

// Include all necessary libraries
#include <stdint.h>
#include <ESP32Servo.h>
#include <Arduino.h>

// Define a namespace 'motors' to encapsulate all motor functions
namespace motors {
    /*
    * Container struct for all servo objects used in the bot
    * This structure centralizes all motor and servo objects for easy access
    */
    struct Container {
        Servo digMotor;         // Motor for the digging mechanism
        Servo actuator;         // Actuator for the digging mechanism
        Servo auger;            // Motor for the deposit system
        Servo vibrator;         // Motor for the deposit vibrator
        Servo driveMotor1;      // Left drive motor
        Servo driveMotor2;      // Right drive motor

        Servo horizontalServo;  // Servo for the horizontal camera servo
        Servo verticalServo;    // Servo for the vertical camera servo
        Servo armServo;         // Servo for the arm servo
    };

    /*
    * Setup function for initializing a motor or servo
    * @param pin The microcontroller pin number to which the motor is connected
    * @param motor Reference to the Servo object representing the motor
    * @param pwmParameter Initial PWM value to set for the motor
    */
    void Setup(uint8_t pin, Servo &motor, uint8_t pwmParamater);

    /*
    * Set the speed/position of a motor or servo
    * @param motor Reference to the Servo object to be controlled
    * @param pwmParameter PWM value to set for the motor
    */
    void Set(Servo &motor, uint8_t pwmParamater);

    /*
    * Stop a motor
    * @param motor Reference to the Servo object to be stopped
    */
    void Stop(Servo &motor);

    /*
    * Set a motor to move forward at full speed
    * @param motor Reference to the Servo object to be moved forward
    */
    void Forward(Servo &motor);

    /*
    * Set a motor to move backward at full speed
    * @param motor Reference to the Servo object to be moved backward
    */
    void Backward(Servo &motor);

    /*
    * Control the drive motors for the bot's movement
    * @param speedLeft Speed value for the left drive motor (0-180)
    * @param speedRight Speed value for the right drive motor (0-180)
    * @param driveMotor1 Reference to the left drive motor
    * @param driveMotor2 Reference to the right drive motor
    */
    void drive(uint8_t speedLeft, uint8_t speedRight, Servo &driveMotor1, Servo &driveMotor2);
}

#endif //Motors_h
