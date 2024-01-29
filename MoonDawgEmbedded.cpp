// Cameron Schwartzberg
// 1/28/2024, 9:28 PM
// embedded-berm-bot
// (Description)
// (Contributors)

#incldue <Wire.h>
#include <SoftwareSerial.h>
#include "RoboClaw.h"
#include "setup.h"
#include "movementBasic.h"


void loop(){

}

void setup(){
    roboclaw.begin(38400);
    Serial.begin(9600);
    Wire.begin(SLAVE_ADDRESS);
    Wire.onReceive(receiveData);

    // Motor setup
    // Sets all motor pins to output and sets all motors to off
    motorSetup(1, 2, 3, 4); // Enter pins here in place of 1, 2, 3, 4
}