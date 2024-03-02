/*
 * This is the Arduino testing code for the MoonDawg rover.
 * This code will be used to test the functionality and viability of the final rover code.
 * The code is based off of last year's code, but modified to use the Servo library to control the motors instead of Serial communication.
 */


//#include <RoboClaw.h>
#include <Servo.h>

#include "PinDefinitions.h"
#include "Movement.h"


// Class constructors
digMovement dig(DIGGING_MOTOR, DIGGING_ACTUATOR);
depositMovement deposit(DEPOSIT_MOTOR);
DriveMotorMovement drive(LEFT_MOTOR, RIGHT_MOTOR); 

bool hold = true;

void setup() {
  // put your setup code here, to run once:
    // For the serial communication from RPi to Arduino
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  drive.driveStraight(120);
  
}
