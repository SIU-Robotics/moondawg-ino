// Cameron Schwartzberg
// 1/28/2024, 9:37 PM
// embedded-berm-bot
// Setup functions
// (Contributors)

#include "setup.h"

void motorSetup(short int x1, short x2, short x3, short x4) {
    pinMode(x1, OUTPUT);
    pinMode(x2, OUTPUT);
    pinMode(x3, OUTPUT);
    pinMode(x4, OUTPUT);

    // Set all motors to off
    digitalWrite(x1, Low);
    digitalWrite(x2, Low);
    digitalWrite(x3, Low);
    digitalWrite(x4, Low);
}
