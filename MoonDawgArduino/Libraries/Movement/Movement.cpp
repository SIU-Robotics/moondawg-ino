// Cameron Schwartzberg
// 2/18/2024, 7:37 PM
// 240216-212839-uno
// (Description)
// (Contributors)

#include "Movement.h"
#include <Arduino.h>


// Add ramping functions, so we don't have to pass speed
// Dig motor movement, will write to the motor, "180" for forward, "0" for backward, "90" for stop
// Actuator movement, will ...
// Actuator movement, not yet implemented
DigMovement::DigMovement() {
    // Empty constructor
}

void DigMovement::digSetup(uint8_t diggingPin, uint8_t actuatorPinOne, uint8_t actuatorPinTwo) {
    pinOneAct = actuatorPinOne;
    pinTwoAct = actuatorPinTwo;
    pinMode(pinOneAct, OUTPUT);
    pinMode(pinTwoAct, OUTPUT);
    digitalWrite(pinOneAct, LOW);
    digitalWrite(pinTwoAct, LOW);
    motor.attach(diggingPin);
    motor.write(90);
}

void DigMovement::digMotorForward(){

    motor.write(180);

}

void DigMovement::digMotorBackward(){
    motor.write(0);
}

void DigMovement::digMotorStop(){
    motor.write(90);
}

void DigMovement::digActuatorForward(){
    digitalWrite(pinTwoAct, LOW);
    digitalWrite(pinOneAct, HIGH);
}

void DigMovement::digActuatorBackward(){
    digitalWrite(pinOneAct, LOW);
    digitalWrite(pinTwoAct, HIGH);
}

void DigMovement::digActuatorStop(){
    digitalWrite(pinOneAct, LOW);
    digitalWrite(pinTwoAct, LOW);
}

// Add ramping functions so we don't have to pass speed
// Deposit motor movement, will write to the motor, "180" for forward, "0" for backward, "90" for stop
DepositMovement::DepositMovement() {

}

void DepositMovement::depositSetup(uint8_t depositPin) {
    motor.attach(depositPin);
    motor.write(90);
}
void DepositMovement::depositMotorForward(){
    motor.write(180);
}

void DepositMovement::depositMotorBackward(){
    motor.write(0);
}

void DepositMovement::depositMotorStop(){
    motor.write(90);
}


// Drive motor movement, will write to the motor
// Haven't decided where input will be taken from yet, once we get the info from what serial and data from that we will be receiving we can decide
// on how to implement the input, from the RPi which will take input from a controller
DriveMovement::DriveMovement() {
    // Empty constructor
}

void DriveMovement::driveSetup(uint8_t leftPin, uint8_t rightPin, uint8_t actuatorTurnPinOne, uint8_t actuatorTurnPinTwo) {
    motor1.attach(leftPin);
    motor2.attach(rightPin);
    motor1.write(90);
    motor2.write(90);
    turnPinOne = actuatorTurnPinOne;
    turnPinTwo = actuatorTurnPinTwo;
    pinMode(turnPinOne, OUTPUT);
    pinMode(turnPinTwo, OUTPUT);
    digitalWrite(turnPinOne, LOW);
    digitalWrite(turnPinTwo, LOW);
}

void DriveMovement::drive(int speedLeft, int speedRight){
    motor1.write(speedLeft);
    motor2.write(speedRight);
}

void DriveMovement::actuatorTurnLeft(){
    digitalWrite(turnPinTwo, LOW);
    digitalWrite(turnPinOne, HIGH);
}

void DriveMovement::actuatorTurnRight(){
    digitalWrite(turnPinOne, LOW);
    digitalWrite(turnPinTwo, HIGH);
}

void DriveMovement::actuatorTurnStop(){
    digitalWrite(turnPinOne, LOW);
    digitalWrite(turnPinTwo, LOW);
}
