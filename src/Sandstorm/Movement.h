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

extern Servo digMotor;
extern Servo actuator;
extern Servo auger;
extern Servo vibrator;
extern Servo driveMotor1;
extern Servo driveMotor2;

void digSetup(uint8_t diggingPin, uint8_t actuatorPin);
void digMotorStart(uint8_t speed);
void digMotorStop();
void digActuatorForward();
void digActuatorBackward();
void digActuatorStop();

void depositSetup(uint8_t depositPin, uint8_t vibratorPin);
void depositMotorForward();
void depositMotorBackward();
void depositMotorStop();
void depositVibrator();
void depositVibratorStop();

void driveSetup(uint8_t leftPin, uint8_t rightPin);
void drive(int speedLeft, int speedRight);

#endif //Movement_h
