// Cameron Schwartzberg
// 1/28/2024, 9:28 PM
// embedded-berm-bot
// (Description)
// (Contributors)

#include <stdio.h>
#include <Servo.h>
#include <cstdint>
#include "Arduino.h"
#include "RoboClaw.h"
#include "setup.h"
#include "movementBasic.h"
#include "pinDefinitions.h"


void loop(){

}

void setup(){
    roboclaw.begin(38400);


    // Motor setup
    // Sets all motor pins to output and sets all motors to off
    motorSetup(); // Enter pins here in place of 1, 2, 3, 4
}