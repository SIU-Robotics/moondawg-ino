// Cameron Schwartzberg
// 2/18/2024, 7:37 PM
// 240216-212839-uno
// Header file that contains all the classes and defines all functions for the "Movement.cpp"
// Cameron Schwartzberg, Marco Caliendo, Andrew Barnes, Nadia Lafontant, Mitchell Wettig

#ifndef Movement_h
#define Movement_h

#include <stdint.h>
#include <Servo.h>
#include <Arduino.h>

#include "PinDefinitions.h"


// Class for the dig motor movement
// Accesses the protected "Servo motor" and "(insert Actuator)" from the digSetup class
class DigMovement {
private:
    Servo motor1;
    Servo motor2;
public:
    DigMovement();
    void digSetup(uint8_t diggingPin, uint8_t actuatorPin);
    void digMotorStart(uint8_t speed);
    void digMotorStop();
    void digActuatorForward();
    void digActuatorBackward();
    void digActuatorStop();
};

// Class for the deposit motor movement
// Accesses the protected "Servo motor" from the depositSetup class
class DepositMovement {
private:
    Servo motor1;
    Servo motor2;
public:
    DepositMovement();
    void depositSetup(uint8_t depositPin, uint8_t vibratorPin);
    void depositMotorForward();
    void depositMotorBackward();
    void depositMotorStop();
    void depositVibrator();
    void depositVibratorStop();
};

// Class for the drive motor movement
// Accesses the protected "Servo motor1" and "Servo motor2" from the driveMotorSetup class
// Uses the "uint8_t" data type for the speed of the motors, which is an 8-bit unsigned integer. From the "stdint.h" library
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
