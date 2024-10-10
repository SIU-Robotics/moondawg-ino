/*
* Owner: Cameron Schwartzberg (BigBroccoli)
* Contributors: Marco Caliendo (MCal88), Andrew Barnes (abarnes6), and Mitchell Wettig
*/

#ifndef Movement_h
#define Movement_h

#include <stdint.h>
#include <ESP32Servo.h>
#include <Arduino.h>

#include "PinDefinitions.h"


void digSetup(uint8_t diggingPin, uint8_t actuatorPin, Servo &digMotor, Servo &actuator);
void digMotorStart(uint8_t speed, Servo &digMotor);
void digMotorStop(Servo &digMotor);
void digActuatorForward(Servo &actuator);
void digActuatorBackward(Servo &actuator);
void digActuatorStop(Servo &actuator);

void depositSetup(uint8_t depositPin, uint8_t vibratorPin, Servo &auger, Servo &vibrator);
void depositMotorForward(Servo &auger);
void depositMotorBackward(Servo &auger);
void depositMotorStop(Servo &auger);
void depositVibrator(Servo &vibrator);
void depositVibratorStop(Servo &vibrator);

void driveSetup(uint8_t leftPin, uint8_t rightPin, Servo &driveMotor1, Servo &driveMotor2);
void drive(int speedLeft, int speedRight, Servo &driveMotor1, Servo &driveMotor2);

#endif //Movement_h
