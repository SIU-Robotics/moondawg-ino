// Cameron Schwartzberg
// 1/28/2024, 9:33 PM
// embedded-berm-bot
// (Description)
// (Contributors)

#ifndef EMBEDDED_BERM_BOT_MOVEMENTBASIC_H
#define EMBEDDED_BERM_BOT_MOVEMENTBASIC_H


class movementBasic {
    void motorsForwardOn(PWM_pin_Motor1, PWM_pin_Motor2, PWM_pin_Motor3, PWM_pin_Motor4);
    void motorsReverseOn(PWM_pin_Motor1, PWM_pin_Motor2, PWM_pin_Motor3, PWM_pin_Motor4);
    void motorsOff(PWM_pin_Motor1, PWM_pin_Motor2, PWM_pin_Motor3, PWM_pin_Motor4);
};


#endif //EMBEDDED_BERM_BOT_MOVEMENTBASIC_H
