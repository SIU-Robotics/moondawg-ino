// Cameron Schwartzberg
// 1/28/2024, 9:33 PM
// embedded-berm-bot
// Basic movement functions
// (Contributors)

#include "movementBasic.h"

void movementBasic::motorsForwardOn(short int x1, short x2, short x3, short x4) {
    digitalWrite(x1, High);
    digitalWrite(x2, Low);
    digitalWrite(x3, High);
    digitalWrite(x4, Low);
}

void movementBasic::motorsReverseOn(short int x1, short x2, short x3, short x4) {
    digitalWrite(x1, Low);
    digitalWrite(x2, High);
    digitalWrite(x3, Low);
    digitalWrite(x4, High);
}

void movementBasic::motorsOff(short int x1, short x2, short x3, short x4) {
    digitalWrite(x1, Low);
    digitalWrite(x2, Low);
    digitalWrite(x3, Low);
    digitalWrite(x4, Low);
}
