#include "Camera.h"
#include <Arduino.h>

CameraControl::CameraControl(){
    //empty constructor
}

CameraControl::cameraSetup(uint8_t horizontalPin, unint8_t verticalPin, unint8_t armPin){
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
    horizontalMaxAngle = 180;
}


// Swings the deployment arm to its final position
// Currently 180 degrees, can change if needed
CameraControl::moveArm(uint8_t armAngle){
    armAngle = armHoldAngle;
}

// Pan servo, gets constrained between its limits
CameraControl::moveHorizontal(uint8_t horizontalAngle){
    horizontalAngle = constrain(horizontalAngle, horizontalMinAngle, horizontalMaxAngle);
    horizontalServo.write(horizontalAngle);
}

// Tilt servo, has internal hard limits
CameraControl::moveVertical(uint8_t verticalAngle){
    vertiaclServo.write(verticalAngle);
}

CameraControl::hold(){
    armServo.write(armHoldAngle);
}