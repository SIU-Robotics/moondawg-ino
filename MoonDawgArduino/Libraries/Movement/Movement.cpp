/*
* This file is connected to "Movement.cpp"
* Owner: Cameron Schwartzberg
* Contributors: Marco Caliendo, Andrew Barnes, and Mitchell Wettig
* Date Created: 2/18/2024
*/

// Calling all libraries
#include "Movement.h"
#include <Arduino.h>

/*
* DigMovement controls the movement of the actuator to swing the bucket conveyor as well as
* the motor which drives the bucket conveyor
* 
* MUST HAVE AN EMPTY DEFAULT CONSTRUCTOR DO NOT LEAVE OUT!!!
* 
* Create a setup this will be called in the setup of your main file to initialize all of the variables used
* SET ALL INITIAL VALUES TO STOP (90)!!!
* 
* The dig motor is being sent a variable from the RPi that controls the speed and direction with a
* function to stop the motor. The Actuator has three commands forward (180), backward (0), and stop (90) to control it
*/
DigMovement::DigMovement() {
    // Empty constructor
}

void DigMovement::digSetup(uint8_t diggingPin, uint8_t actuatorPin) {
    motor1.attach(diggingPin);
    motor2.attach(actuatorPin);
    motor1.write(90);
    motor2.write(90);
}

void DigMovement::digMotorStart(uint8_t speed){
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

/*
* DepositMovement controls the movement of the auger motor as well as the vibrator
* 
* MUST HAVE AN EMPTY DEFAULT CONSTRUCTOR DO NOT LEAVE OUT!!!
* 
* Create a setup this will be called in the setup of your main file to initialize all of the variables used 
* SET ALL INITIAL VALUES TO STOP (90)!!!
* 
* The Dig motor is being sent a variable from the RPi that gives a command for both the auger motor and vibrator
* The auger and vibrator each have three commands forward (180), backward (0), and stop (90) to control it
*/
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

/*
* DriveMovement controls the movement of the drive motors for the locomotion of the bot
* 
* MUST HAVE AN EMPTY DEFAULT CONSTRUCTOR DO NOT LEAVE OUT!!!
* 
* Create a setup this will be called in the setup of your main file to initialize all of the variables used 
* SET ALL INITIAL VALUES TO STOP (90)!!!
* 
* The Drive motors are being sent variables from the RPi that controls the speed and direction. Two of the motors are tied together
* this is why there are only two motors in these functions
*/
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
