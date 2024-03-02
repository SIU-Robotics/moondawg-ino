// Cameron Schwartzberg
// 2/18/2024, 7:37 PM
// 240216-212839-uno
// (Description)
// (Contributors)

#include "Movement.h"
#include "PinDefinitions.h"
#include <Servo.h>
#include <Arduino.h>

// Add ramping functions so we don't have to pass speed
// Dig motor movement, will write to the motor, "180" for forward, "0" for backward, "90" for stop
// Actuator movement, will ...
// Actuator movement, not yet implemented
void digMovement::digMotorForward(){
    motor.write(180);
}

void digMovement::digMotorBackward(){
    motor.write(0);
}

void digMovement::digMotorStop(){
    motor.write(90);
}

// Add ramping functions so we don't have to pass speed
// Deposit motor movement, will write to the motor, "180" for forward, "0" for backward, "90" for stop
void depositMovement::depositMotorForward(){
    motor.write(180);
}

void depositMovement::depositMotorBackward(){
    motor.write(0);
}

void depositMovement::depositMotorStop(){
    motor.write(90);
}


// Drive motor movement, will write to the motor
// Haven't decided where input will be taken from yet, once we get the info from what serial and data from that we will be receiving we can decide
// on how to implement the input, from the RPi which will take input from a controller
DriveMotorMovement::DriveMotorMovement(int leftPin, int rightPin) {
    pinMode(leftPin, OUTPUT);
    pinMode(rightPin, OUTPUT);
    motor1.attach(leftPin);
    motor2.attach(rightPin);
    motor1.write(90);
    motor2.write(90);
}

void DriveMotorMovement::driveStraight(int speedLeft, int speedRight){
    motor1.write(speedLeft);
    motor2.write(speedRight);
}
