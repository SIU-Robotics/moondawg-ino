// Cameron Schwartzberg
// 2/18/2024, 7:37 PM
// 240216-212839-uno
// (Description)
// (Contributors)

#ifndef Movement_h
#define Movement_h

#include <stdint.h>
#include "PinDefinitions.h"
#include <Servo.h>
#include "Arduino.h"


// Class for the dig motor movement
// Accesses the protected "Servo motor" and "(insert Actuator)" from the digSetup class
class digMovement {
private:
    Servo motor;
public:
    digMovement(uint8_t diggingPin, uint8_t actuatorDigPin){
        motor.attach(diggingPin);
        motor.write(90);
    }
    void digMotorForward();
    void digMotorBackward();
    void digMotorStop();
    void digActuatorForward();
    void digActuatorBackward();
    void digActuatorStop();
};

// Class for the deposit motor movement
// Accesses the protected "Servo motor" from the depositSetup class
class depositMovement {
private:
    Servo motor;
public:
    depositMovement(uint8_t depositPin){
        motor.attach(depositPin);
        motor.write(90);
    }
    void depositMotorForward();
    void depositMotorBackward();
    void depositMotorStop();
};

// Class for the drive motor movement
// Accesses the protected "Servo motor1" and "Servo motor2" from the driveMotorSetup class
// Uses the "uint8_t" data type for the speed of the motors, which is an 8-bit unsigned integer. From the "stdint.h" library
class DriveMotorMovement{
private:
    Servo motor1;
    Servo motor2;
    float medTurn = 0; // Equation for one side going slower than other
public:
    DriveMotorMovement(int leftPin, int rightPin);
    void driveStraight(int speedLeft, int speedRight);
};


#endif //Movement_h
