/*
* This file is connected to "Movement.cpp"
* Owner: Cameron Schwartzberg (BigBroccoli)
* Contributors: Marco Caliendo (MCal88), Andrew Barnes (abarnes6), and Mitchell Wettig
*/

#include "Movement.h"
#include <Arduino.h>
#include <ESP32Servo.h>

Servo digMotor;
Servo actuator;
Servo auger;
Servo vibrator;
Servo driveMotor1;
Servo driveMotor2;

/*
* Use the setup function this will be called in the setup of your main file to initialize all of the variables used and attach
* the motors to the pins
* SET ALL INITIAL VALUES TO STOP (90)!!!
* 
* The motors are being sent a variable from the RPi that controls the speed and direction with a
* function to stop the motor. The motors/actuator have three commands forward (180), backward (0), and stop (90) to control it
* and numbers between to control the speed
* 
* For the drive motors, two are tied together in hardware so they will be controlled together in the function call
* this is why there are only two motors in these functions
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
