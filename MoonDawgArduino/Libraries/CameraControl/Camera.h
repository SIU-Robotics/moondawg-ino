#ifndef Camera_h
#define Camera_h

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
    uint8_t horizontalMaxAngle;
public:
    CameraControl();
    void cameraSetup(uint8_t horizontalPin, unint8_t verticalPin, unint9_t armPin);
    void moveHorizontal(uint8_t horizontalAngle);
    void moveVertical(uint8_t verticalAngle);
    void deploy();
};

#endif //Camera_h