/*
* Owner: Marco Caliendo (MCal88)
* Contributors: Cameron Schwartzberg (BigBroccoli)
*/
#ifndef Camera_h
#define Camera_h

#include <stdint.h>
#include <ESP32Servo.h>
#include <Arduino.h>

#include "Camera.h"



void cameraSetup(uint8_t horizontalPin, uint8_t verticalPin, uint8_t armPin, Servo &horizontalServo, Servo &verticalServo, Servo &armServo);
void moveHorizontal(uint8_t horizontalAngle, Servo &horizontalServo);
void moveVertical(uint8_t verticalAngle, Servo &verticalServo);
void moveArmHold(uint8_t armAngle, Servo &armServo);


#endif //Camera_h
