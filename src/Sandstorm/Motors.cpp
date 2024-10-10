/*
* Motors.cpp - Implementation file for motor control functions for the Sandstorm 2024 Lunabotics bot.
* 
* This file contains the implementation of functions for controlling the various motors and servos
* used in the bot's operation.
*
* Owner: Cameron Schwartzberg (BigBroccoli)
* Contributors: Marco Caliendo (MCal88), Andrew Barnes (abarnes6), and Mitchell Wettig
*/

#include "Motors.h"


namespace motors {
    /*
    * Setup function for initializing a motor or servo
    * @param pin The microcontroller pin number to which the motor is connected
    * @param motor Reference to the Servo object representing the motor
    * @param pwmParameter Initial PWM value to set for the motor
    */
    void Setup(uint8_t pin, Servo &motor, uint8_t pwmParamater) {
        motor.attach(pin);
        motor.write(pwmParamater);
    }

    /*
    * Set the speed/position of a motor or servo
    * @param motor Reference to the Servo object to be controlled
    * @param pwmParameter PWM value to set for the motor
    */
    void Set(Servo &motor, uint8_t speed) {
        motor.write(speed);
    }

    /*
    * Stop a motor
    * @param motor Reference to the Servo object to be stopped
    */
    void Stop(Servo &motor) {
        Set(motor, 90);
    }

    /*
    * Set a motor to move forward at full speed
    * @param motor Reference to the Servo object to be moved forward
    */
    void Forward(Servo &motor) {
        Set(motor, 180);
    }

    /*
    * Set a motor to move backward at full speed
    * @param motor Reference to the Servo object to be moved backward
    */
    void Backward(Servo &motor) {
        Set(motor, 0);
    }

    /*
    * Motor Control System Overview:
    * 
    * - Use the Setup function in the main file's setup() to initialize all motors and attach them to pins.
    * - IMPORTANT: Set all initial values to STOP (90) for safety!
    * 
    * - The motors receive control variables from the RPi to manage speed and direction.
    * - Motor/actuator commands:
    *   - Forward: 180
    *   - Backward: 0
    *   - Stop: 90
    *   - Speed control: Values between 0-180 (for servos) or 0-255 (for DC motors)
    * 
    * - Drive motors: Two motors are controlled together in hardware, hence only two motor parameters in the drive function.
    */

    /*
    * Control the drive motors for the bot's movement
    * @param speedLeft Speed value for the left drive motor (0-180)
    * @param speedRight Speed value for the right drive motor (0-180)
    * @param driveMotor1 Reference to the left drive motor
    * @param driveMotor2 Reference to the right drive motor
    */
    void drive(uint8_t speedLeft, uint8_t speedRight, Servo &driveMotor1, Servo &driveMotor2) {
        driveMotor1.write(speedLeft);
        driveMotor2.write(speedRight);
    }
}