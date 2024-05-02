#include "Camera.h"
#include <Arduino.h>

CameraControl::CameraControl(){
    //empty constructor
}

void CameraControl::cameraSetup(uint8_t horizontalPin, uint8_t verticalPin, uint8_t armPin){
    horizontalServo.attach(horizontalPin);
    verticalServo.attach(verticalPin);
    armServo.attach(armPin);
    horizontalServo.write(90);
    verticalServo.write(90);
    // Initial position for deployment servo
    // Can change if needed
    armServo.write(0);
    // Defines the limits for the horizontal servo
    // Helps to prevent the cable from getting wrapped around the servo
    // Can change to higher values if needed
    horizontalMinAngle = 0;
    horizontalMaxAngle = 359;
}


// Swings the deployment arm to its final position
// Currently 180 degrees, can change if needed
void CameraControl::moveArmHold(uint8_t armAngle){
    armHoldAngle = armAngle;
}

// Pan servo, gets constrained between its limits
void CameraControl::moveHorizontal(uint8_t horizontalAngle){
    horizontalAngle = constrain(horizontalAngle, horizontalMinAngle, horizontalMaxAngle);
    horizontalServo.write(horizontalAngle);
}

// Tilt servo, has internal hard limits
void CameraControl::moveVertical(uint8_t verticalAngle){
    verticalServo.write(verticalAngle);
}

void CameraControl::hold(){
    armServo.write(armHoldAngle);
}