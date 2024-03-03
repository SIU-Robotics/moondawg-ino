// Cameron Schwartzberg
// 2/18/2024, 7:37 PM
// 240216-212839-uno
// (Description)
// (Contributors)

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
    Servo motor;
    uint8_t pinOneAct;
    uint8_t pinTwoAct;
public:
    DigMovement();
    void digSetup(uint8_t diggingPin, uint8_t actuatorPinOne, uint8_t actuatorPinTwo);
    void digMotorForward();
    void digMotorBackward();
    void digMotorStop();
    void digActuatorForward();
    void digActuatorBackward();
    void digActuatorStop();
};

// Class for the deposit motor movement
// Accesses the protected "Servo motor" from the depositSetup class
class DepositMovement {
private:
    Servo motor;
public:
    DepositMovement();
    void depositSetup(uint8_t depositPin);
    void depositMotorForward();
    void depositMotorBackward();
    void depositMotorStop();
};

// Class for the drive motor movement
// Accesses the protected "Servo motor1" and "Servo motor2" from the driveMotorSetup class
// Uses the "uint8_t" data type for the speed of the motors, which is an 8-bit unsigned integer. From the "stdint.h" library
class DriveMovement{
private:
    Servo motor1;
    Servo motor2;
    uint8_t turnPinOne;
    uint8_t turnPinTwo;
public:
    DriveMovement();
    void driveSetup(uint8_t leftPin, uint8_t rightPin, uint8_t actuatorTurnPinOne, uint8_t actuatorTurnPinTwo);
    void drive(int speedLeft, int speedRight);
    void actuatorTurnLeft();
    void actuatorTurnRight();
    void actuatorTurnStop();
};


#endif //Movement_h
