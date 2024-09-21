/*
* Owner: Marco Caliendo (MCal88)
* Contributors: Cameron Schwartzberg (BigBroccoli)
*/

#include "Camera.h"
#include <Arduino.h>
#include <Servo.h>

Servo horizontalServo;
Servo verticalServo;
Servo armServo;

/*
* CameraControl controls the movement of the servos to move the camera around
* 
* MUST HAVE AN EMPTY DEFAULT CONSTRUCTOR DO NOT LEAVE OUT!!!
* 
* Create a setup this will be called in the setup of your main file to initialize all of the variables used
* SET ALL INITIAL VALUES TO STOP (90)!!!
* 
* The servos are being sent a variable from the RPi that controls the speed and direction with a
* function that will continue to hold the angle it was last sent
*/
void cameraSetup(uint8_t horizontalPin, uint8_t verticalPin, uint8_t armPin){
    horizontalServo.attach(horizontalPin);
    verticalServo.attach(verticalPin);
    armServo.attach(armPin);
    horizontalServo.write(180);
    verticalServo.write(90);
    armServo.write(0);      // Initial position for deployment servo
}


// Swings the deployment arm to its final position
// Currently 180 degrees, can change if needed
void moveArmHold(uint8_t armAngle){
    armServo.write(armAngle);
}

// Pan servo, gets constrained between its limits
void moveHorizontal(uint8_t horizontalAngle){
    horizontalServo.write(horizontalAngle);
}

// Tilt servo, has internal hard limits
void moveVertical(uint8_t verticalAngle){
    verticalServo.write(verticalAngle);
}
