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
namespace motors
{
        /*
         * Container struct for all servo objects used in the bot
         * This structure centralizes all motor and servo objects for easy access
         */
        struct Container
        {
                Servo driveMotorFL; // drive motor
                Servo driveMotorFR; // drive motor
                Servo driveMotorRL; // drive motor
                Servo driveMotorRR; // drive motor
                Servo turnMotorFL;
                Servo turnMotorFR;
                Servo turnMotorRL;
                Servo turnMotorRR;
                Servo beltMotor;  // Motor for the excavation system
                Servo augerMotor; // Motor for the excavation system
                Servo lActuator;  // Actuator for the excavation system
                Servo rActuator;  // Second actuator for the excavation system
                Servo cameraYaw;
                Servo cameraPitch;
                Servo vibe;
        };

        /*
         * Setup function for initializing a motor or servo
         * @param pin The microcontroller pin number to which the motor is connected
         * @param motor Reference to the Servo object representing the motor
         * @param pwmParameter Initial PWM value to set for the motor
         */
        inline void Setup(const uint8_t pin, Servo &motor, const uint8_t pwmParameter)
        {
                motor.attach(pin);
                motor.write(pwmParameter);
        }

        /*
         * Set the speed/position of a motor or servo
         * @param motor Reference to the Servo object to be controlled
         * @param pwmParameter PWM value to set for the motor
         */
        inline void Set(Servo &motor, uint8_t speed)
        {
                motor.write(speed);
        }
}

#endif // Motors_h
