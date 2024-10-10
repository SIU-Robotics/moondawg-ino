/*
* This file is connected to "Movement.cpp"
* Owner: Cameron Schwartzberg (BigBroccoli)
* Contributors: Marco Caliendo (MCal88), Andrew Barnes (abarnes6), and Mitchell Wettig
*/

#include "Movement.h"
#include <Arduino.h>
#include <ESP32Servo.h>


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
void digSetup(uint8_t diggingPin, uint8_t actuatorPin, Servo &digMotor, Servo &actuator) {
    digMotor.attach(diggingPin);
    actuator.attach(actuatorPin);
    digMotor.write(90);
    actuator.write(90);
}

void digMotorStart(uint8_t speed, Servo &digMotor){
    digMotor.write(speed);
}

void digMotorStop(Servo &digMotor){
    digMotor.write(90);
}

void digActuatorForward(Servo &actuator){
    actuator.write(180);
}

void digActuatorBackward(Servo &actuator){
    actuator.write(0);
}

void digActuatorStop(Servo &actuator){
    actuator.write(90);
}


void depositSetup(uint8_t depositPin, uint8_t vibratorPin, Servo &auger, Servo &vibrator) {
    auger.attach(depositPin);
    vibrator.attach(vibratorPin);
    auger.write(90);
    vibrator.write(90);
}

void depositMotorForward(Servo &auger){
    auger.write(180);
}

void depositMotorBackward(Servo &auger){
    auger.write(0);
}

void depositMotorStop(Servo &auger){
    auger.write(90);
}

void depositVibrator(Servo &vibrator){
    vibrator.write(180);
}

void depositVibratorStop(Servo &vibrator){
    vibrator.write(90);
}


void driveSetup(uint8_t leftPin, uint8_t rightPin, Servo &driveMotor1, Servo &driveMotor2) {
    driveMotor1.attach(leftPin);
    driveMotor2.attach(rightPin);
    driveMotor1.write(90);
    driveMotor2.write(90);

}

void drive(int speedLeft, int speedRight, Servo &driveMotor1, Servo &driveMotor2) {
    driveMotor1.write(speedLeft);
    driveMotor2.write(speedRight);
}
