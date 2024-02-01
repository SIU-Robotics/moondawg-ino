// Cameron Schwartzberg
// 1/28/2024, 9:37 PM
// embedded-berm-bot
// Setup functions
// (Contributors)

#include <Servo.h>
#include "pinDefinitions.h"
#include "setup.h"

void motorSetup(PWM_pin_Motor1, PWM_pin_Motor2, PWM_pin_Motor3, PWM_pin_Motor4)) {
    motor1.attach(PWM_pin_Motor1);
    motor2.attach(PWM_pin_Motor2);
    motor3.attach(PWM_pin_Motor3);
    motor4.attach(PWM_pin_Motor4);
    motor1.write(90);
    motor2.write(90);
    motor3.write(90);
    motor4.write(90);
}
