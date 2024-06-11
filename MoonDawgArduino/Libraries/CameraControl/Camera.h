/*
* This file is connected to "Camera.cpp"
* Owner: Marco Caliendo
* Contributors: Cameron Schwartzberg and Andrew Barnes
* Date Created: 4/25/2024
*/
#ifndef Camera_h
#define Camera_h

// Include all libraries
#include <stdint.h>
#include <Servo.h>
#include <Arduino.h>

#include "Camera.h"


/*
* Class for camera control
* Private (things we don't want to be used by functions outside of this class):
* Uses the Servo library to create controllable servos
* Defines the minimum and maximum angles for the horizontal servo
* Defines a holding variable for the servo arm to continually get sent
* Public:
* This houses all of the functions that will be used by the main program
*/
class CameraControl {
private:
    Servo horizontalServo;
    Servo verticalServo;
    Servo armServo;
    uint8_t horizontalMinAngle;
    uint16_t horizontalMaxAngle;
    uint8_t armHoldAngle;
public:
    CameraControl();
    void cameraSetup(uint8_t horizontalPin, uint8_t verticalPin, uint8_t armPin);
    void moveHorizontal(uint8_t horizontalAngle);
    void moveVertical(uint8_t verticalAngle);
    void moveArmHold(uint8_t armAngle);
};

#endif //Camera_h
