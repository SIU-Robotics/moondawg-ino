/*
 * This is the Arduino testing code for the MoonDawg rover.
 * This code will be used to test the functionality and viability of the final rover code.
 * The code is based off of last year's code, but modified to use the Servo library to control the motors instead of Serial communication.
 */
// Cameron Schwartzberg
// 2/18/2024, 7:07 PM
// 240216-212839-uno
// (Description)
// (Contributors)

#include <Servo.h>
#include <Arduino.h>

#include "PinDefinitions.h"
#include "Movement.h"


// Class constructors
DriveMovement driving = DriveMovement();
DepositMovement depositing = DepositMovement();
DigMovement digging = DigMovement();

bool hold = true;

void setup() {
  // put your setup code here, to run once:
    // For the serial communication from RPi to Arduino
    // Serial.begin(9600);

    driving.driveSetup(LEFT_MOTOR, RIGHT_MOTOR, TURNING_ACTUATOR_ONE, TURNING_ACTUATOR_TWO);
    depositing.depositSetup(DEPOSIT_MOTOR);
    digging.digSetup(DIGGING_MOTOR, DIGGING_ACTUATOR_ONE, DIGGING_ACTUATOR_TWO);
}

void loop() {
  // put your main code here, to run repeatedly

  driving.drive(120, 120);

  
}
