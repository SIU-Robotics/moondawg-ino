/*
* This file is connected to "Movement.cpp"
* Owner: Cameron Schwartzberg
* Contributors: Marco Caliendo, Andrew Barnes, and Mitchell Wettig
* Date Created: 2/18/2024
*/

#ifndef Movement_h
#define Movement_h

// Calling all libraries 
#include <stdint.h>
#include <Servo.h>
#include <Arduino.h>

#include "PinDefinitions.h"

/*
* Class for the Dig Movement
*/
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

/*
* Class for the Deposit movement
*/
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

/*
* Class for the Drive movement
* Private (things we don't want to be used by functions outside of this class):
* This is the for using the Servo Library to create a controllable motor
* Public:
* This houses all of the functions that will be used by the main program
*/
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
