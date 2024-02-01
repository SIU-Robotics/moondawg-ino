// Cameron Schwartzberg
// 1/28/2024, 9:37 PM
// embedded-berm-bot
// (Description)
// (Contributors)

#ifndef EMBEDDED_BERM_BOT_SETUP_H
#define EMBEDDED_BERM_BOT_SETUP_H

#include <Servo.h>
#include "pinDefinitions.h"

class setup {
private:
    Servo motor1;
    Servo motor2;
    Servo motor3;
    Servo motor4;
public:
    void motorSetup(PWM_pin_Motor1, PWM_pin_Motor2, PWM_pin_Motor3, PWM_pin_Motor4);
};


#endif //EMBEDDED_BERM_BOT_SETUP_H
