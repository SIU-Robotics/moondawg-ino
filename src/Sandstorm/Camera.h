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


extern Servo horizontalServo;
extern Servo verticalServo;
extern Servo armServo;

void cameraSetup(uint8_t horizontalPin, uint8_t verticalPin, uint8_t armPin);
void moveHorizontal(uint8_t horizontalAngle);
void moveVertical(uint8_t verticalAngle);
void moveArmHold(uint8_t armAngle);


#endif //Camera_h
