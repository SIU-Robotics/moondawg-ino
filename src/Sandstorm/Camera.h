/*
* Owner: Marco Caliendo (MCal88)
* Contributors: Cameron Schwartzberg (BigBroccoli)
*/
#ifndef Camera_h
#define Camera_h

#include <stdint.h>
#include <Servo.h>
#include <Arduino.h>

#include "Camera.h"


/*
* Class for camera control
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
