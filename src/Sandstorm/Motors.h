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
    constexpr uint8_t STOP_VALUE = 90;
    constexpr uint8_t FORWARD_VALUE = 180;
    constexpr uint8_t BACKWARD_VALUE = 0;
    /*
    * Container struct for all servo objects used in the bot
    * This structure centralizes all motor and servo objects for easy access
    */
    struct Container {
        #ifdef USE_DRIVE_SYSTEM
            Servo driveMotor;       // drive motor
        #endif

        #ifdef USE_TURN_SYSTEM
            Servo turnMotor;
        #endif

        #ifdef USE_DIGGING_SYSTEM
            Servo digMotor;         // Motor for the digging mechanism
            Servo actuator;         // Actuator for the digging mechanism
        #endif
        
        #ifdef USE_DEPOSIT_SYSTEM
            Servo auger;            // Motor for the deposit system
            Servo vibrator;         // Motor for the deposit vibrator
        #endif

        #ifdef USE_CAMERA_SYSTEM
            Servo horizontalServo;  // Servo for the horizontal camera servo
            Servo verticalServo;    // Servo for the vertical camera servo
            Servo armServo;         // Servo for the arm servo
        #endif
    };

    /*
    * Setup function for initializing a motor or servo
    * @param pin The microcontroller pin number to which the motor is connected
    * @param motor Reference to the Servo object representing the motor
    * @param pwmParameter Initial PWM value to set for the motor
    */
    inline void Setup(const uint8_t pin, Servo &motor, const uint8_t pwmParameter) {
        motor.attach(pin);
        motor.write(pwmParameter);
    }

    /*
    * Set the speed/position of a motor or servo
    * @param motor Reference to the Servo object to be controlled
    * @param pwmParameter PWM value to set for the motor
    */
    inline void Set(Servo &motor, uint8_t speed) {
        motor.write(speed);
    }

    /*
    * Stop a motor
    * @param motor Reference to the Servo object to be stopped
    */
    inline void Stop(Servo &motor) {
        Set(motor, STOP_VALUE);
    }

    /*
    * Set a motor to move forward at full speed
    * @param motor Reference to the Servo object to be moved forward
    */
    inline void Forward(Servo &motor) {
        Set(motor, FORWARD_VALUE);
    }

    /*
    * Set a motor to move backward at full speed
    * @param motor Reference to the Servo object to be moved backward
    */
    inline void Backward(Servo &motor) {
        Set(motor, BACKWARD_VALUE);
    }
}

#endif //Motors_h
