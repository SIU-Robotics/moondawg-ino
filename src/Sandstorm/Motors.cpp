/*
* This file is connected to "Movement.cpp"
* Owner: Cameron Schwartzberg (BigBroccoli)
* Contributors: Marco Caliendo (MCal88), Andrew Barnes (abarnes6), and Mitchell Wettig
*/

#include "Motors.h"


namespace motors {
    void Setup(uint8_t pin, Servo &motor, uint8_t pwmParamater) {
        motor.attach(pin);
        motor.write(pwmParamater);
    }

    void Set(Servo &motor, uint8_t speed) {
        motor.write(speed);
    }

    void Stop(Servo &motor) {
        Set(motor, 90);
    }

    void Forward(Servo &motor) {
        Set(motor, 180);
    }

    void Backward(Servo &motor) {
        Set(motor, 0);
    }

    /*
    * Use the setup function this will be called in the setup of your main file to initialize all of the variables used and attach
    * the motors to the pins
    * SET ALL INITIAL VALUES TO STOP (90)!!!
    * 
    * The motors are being sent a variable from the RPi that controls the speed and direction with a
    * function to stop the motor. The motors/actuator have three commands forward (180), backward (0), and stop (90) to control it
    * and numbers between to control the speed
    * 
    * For the drive motors, two are tied together in hardware so they will be controlled together in the function call
    * this is why there are only two motors in these functions
    */


    void drive(uint8_t speedLeft, uint8_t speedRight, Servo &driveMotor1, Servo &driveMotor2) {
        driveMotor1.write(speedLeft);
        driveMotor2.write(speedRight);
    }
}