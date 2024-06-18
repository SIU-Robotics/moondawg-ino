/*
* Owner: Cameron Schwartzberg (BigBroccoli)
* Contributors: Marco Caliendo (MCal88), Andrew Barnes (abarnes6), and Mitchell Wettig
*/

#ifndef Movement_h
#define Movement_h

#include <stdint.h>
#include <Servo.h>
#include <Arduino.h>

#include "PinDefinitions.h"


class DigMovement {
private:
    Servo motor1; // Dig motor
    Servo motor2; // Actuator
public:
    DigMovement();
    void digSetup(uint8_t diggingPin, uint8_t actuatorPin);
    void digMotorStart(uint8_t speed);
    void digMotorStop();
    void digActuatorForward();
    void digActuatorBackward();
    void digActuatorStop();
};


class DepositMovement {
private:
    Servo motor1; // Auger
    Servo motor2; // Vibrator
public:
    DepositMovement();
    void depositSetup(uint8_t depositPin, uint8_t vibratorPin);
    void depositMotorForward();
    void depositMotorBackward();
    void depositMotorStop();
    void depositVibrator();
    void depositVibratorStop();
};


class DriveMovement{
private:
    Servo motor1;
    Servo motor2;
public:
    DriveMovement();
    void driveSetup(uint8_t leftPin, uint8_t rightPin);
    void drive(int speedLeft, int speedRight);
};

#endif //Movement_h
