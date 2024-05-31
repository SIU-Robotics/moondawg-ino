/*
* This is the library the houses all of the functions and classes for the camera movement
* This file is the header of the library which has function declarations and classes
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


// Camera control class
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
