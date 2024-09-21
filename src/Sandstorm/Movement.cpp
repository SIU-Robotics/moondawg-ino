/*
* This file is connected to "Movement.cpp"
* Owner: Cameron Schwartzberg (BigBroccoli)
* Contributors: Marco Caliendo (MCal88), Andrew Barnes (abarnes6), and Mitchell Wettig
*/

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
void digSetup(uint8_t diggingPin, uint8_t actuatorPin) {
    digMotor.attach(diggingPin);
    actuator.attach(actuatorPin);
    digMotor.write(90);
    actuator.write(90);
}

void digMotorStart(uint8_t speed){
    digMotor.write(speed);
}

void digMotorStop(){
    digMotor.write(90);
}

void digActuatorForward(){
    actuator.write(180);
}

void digActuatorBackward(){
    actuator.write(0);
}

void digActuatorStop(){
    actuator.write(90);
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
void depositSetup(uint8_t depositPin, uint8_t vibratorPin) {
    auger.attach(depositPin);
    vibrator.attach(vibratorPin);
    auger.write(90);
    vibrator.write(90);
}

void depositMotorForward(){
    auger.write(180);
}

void depositMotorBackward(){
    auger.write(0);
}

void depositMotorStop(){
    auger.write(90);
}

void depositVibrator(){
    vibrator.write(180);
}

void depositVibratorStop(){
    vibrator.write(90);
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
void driveSetup(uint8_t leftPin, uint8_t rightPin) {
    driveMotor1.attach(leftPin);
    driveMotor2.attach(rightPin);
    driveMotor1.write(90);
    driveMotor2.write(90);

}

void drive(int speedLeft, int speedRight){
    driveMotor1.write(speedLeft);
    driveMotor2.write(speedRight);
}
