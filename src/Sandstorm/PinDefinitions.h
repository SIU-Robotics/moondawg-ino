/*
* This is the header file that houses all of the pin definitions for the bot
* Owner: Cameron Schwartzberg (BigBroccoli)
* Contributors: Marco Caliendo (MCal88), Joshua Greuel, Andrew Barnes (abarnes6) and Mitchell Wettig
* Date Created: 2/18/2024
*/

#ifndef PinDefinitions_h
#define PinDefinitions_h

// Include standard integer library for uint8_t type
#include <stdint.h>

// Define a namespace 'pin' to encapsulate all pin definitions
namespace pin{
    /*
    * Pin definitions for the motor controllers and other components
    * connected to the output pins of the microcontroller
    *
    * IMPORTANT: PINS MUST BE UPDATED AS PIN LAYOUT CHANGES!!
    * IF NOT CHANGED, NOTHING WILL WORK!!
    */

    // Drive motor pins
    constexpr uint8_t LEFT_MOTOR = 4;           // Pin for the left motors
    constexpr uint8_t RIGHT_MOTOR = 11;         // Pin for the right motors

    // Digging mechanism pins
    constexpr uint8_t DIGGING_MOTOR = 6;        // Pin for the digging motor
    constexpr uint8_t DIGGING_ACTUATOR = 10;    // Pin for the digging actuator

    // Deposit system pins
    constexpr uint8_t DEPOSIT_MOTOR = 5;        // Pin for the deposit motor
    constexpr uint8_t DEPOSIT_VIBRATOR = 9;     // Pin for the deposit vibrator

    // Camera servo pins
    constexpr uint8_t HORIZONTAL_SERVO = 7;     // Pin for the horizontal camera servo
    constexpr uint8_t VERTICAL_SERVO = 8;       // Pin for the vertical camera servo
    constexpr uint8_t ARM_SERVO = 13;           // Pin for the arm servo


    // Encoder pins
    // Note: These are placeholder values and should be updated with the actual pin numbers
    constexpr uint8_t FRONT_RIGHT_WHEEL_ENCODER_PIN1 = 2;
    constexpr uint8_t FRONT_RIGHT_WHEEL_ENCODER_PIN2 = 3;
    constexpr uint8_t FRONT_LEFT_WHEEL_ENCODER_PIN1 = 0;
    constexpr uint8_t FRONT_LEFT_WHEEL_ENCODER_PIN2 = 0;
    constexpr uint8_t REAR_RIGHT_ENCODER_PIN1 = 0;
    constexpr uint8_t REAR_RIGHT_ENCODER_PIN2 = 0;
    constexpr uint8_t REAR_LEFT_ENCODER_PIN1 = 0;
    constexpr uint8_t REAR_LEFT_ENCODER_PIN2 = 0;
}

#endif //PinDefinitions_h
