// Cameron Schwartzberg
// 2/18/2024, 7:37 PM
// This is the corresponding file to the "Movement.h", it contains all the function definitions.
// Cameron Schwartzberg, Marco Caliendo, Mitchell Wettig, Andrew Barnes

#include "Movement.h"
#include <Arduino.h>
#include <TaskSchedule.h>

// Dig motor movement, will write to the motor, "180" for forward, "0" for backward, "90" for stop
// Actuator movement, will write to the pins "LOW" or "HIGH" depending on the action that is wanting to be done.
DigMovement::DigMovement() {
    // Empty constructor
}

void DigMovement::digSetup(uint8_t diggingPin, uint8_t actuatorPin) {
    motor1.attach(diggingPin);
    motor2.attach(actuatorPin);
    motor1.write(90);
    motor2.write(90);
}

void DigMovement::digMotor(uint8_t speed){
    motor1.write(speed);
}

void DigMovement::digMotorStop(){
    motor1.write(90);
}

void DigMovement::digActuatorForward(){
    motor2.write(180);
}

void DigMovement::digActuatorBackward(){
    motor2.write(0);
}

void DigMovement::digActuatorStop(){
    motor2.write(90);
}

// Add ramping functions, so we don't have to pass speed
// Deposit motor movement, will write to the motor, "180" for forward, "0" for backward, "90" for stop
DepositMovement::DepositMovement() {
    // Empty Constructor
}

void DepositMovement::depositSetup(uint8_t depositPin, uint8_t vibratorPin) {
    motor1.attach(depositPin);
    motor2.attach(vibratorPin);
    motor1.write(90);
    motor2.write(90);
}
void DepositMovement::depositMotorForward(){
    motor1.write(180);
}

void DepositMovement::depositMotorBackward(){
    motor1.write(0);
}

void DepositMovement::depositMotorStop(){
    motor1.write(90);
}

void DepositMovement::depositVibrator(){
    motor2.write(180);
}

void DepositMovement::depositVibratorStop(){
    motor2.write(90);
}


// Drive motor movement, will write to the motor
// Takes data from the serial connection and then sends that to the function "drive" which writes to the motors controlling direction and speed
DriveMovement::DriveMovement() {
    // Empty constructor
}

void DriveMovement::driveSetup(uint8_t leftPin, uint8_t rightPin) {
    motor1.attach(leftPin);
    motor2.attach(rightPin);
    motor1.write(90);
    motor2.write(90);

}

void DriveMovement::drive(int speedLeft, int speedRight){
    motor1.write(speedLeft);
    motor2.write(speedRight);
}


SubRoutines::SubRoutines() {
    // Empty constructor
}

void SubRoutines::task1Deposit() {

}