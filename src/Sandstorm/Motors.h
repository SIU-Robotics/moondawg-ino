/*
* Owner: Cameron Schwartzberg (BigBroccoli)
* Contributors: Marco Caliendo (MCal88), Andrew Barnes (abarnes6), and Mitchell Wettig
*/

#ifndef Motors_h
#define Motors_h

#include <stdint.h>
#include <ESP32Servo.h>
#include <Arduino.h>


namespace motors {
    struct Container {
        Servo digMotor;
        Servo actuator;
        Servo auger;
        Servo vibrator;
        Servo driveMotor1;
        Servo driveMotor2;

        Servo horizontalServo;
        Servo verticalServo;
        Servo armServo;
    };


    void Setup(uint8_t pin, Servo &motor, uint8_t pwmParamater);
    void Set(Servo &motor, uint8_t pwmParamater);
    void Stop(Servo &motor);
    void Forward(Servo &motor);
    void Backward(Servo &motor);


    void drive(uint8_t speedLeft, uint8_t speedRight, Servo &driveMotor1, Servo &driveMotor2);
}

#endif //Motors_h
