/*
* This is the library that houses all of the pin definitions for the bot
* Owner: Cameron Schwartzberg
* Contributors: Marco Caliendo, Joshua Greuel, and Mitchell Wettig
* Date Created: 2/18/2024
*/

#ifndef PinDefinitions_h
#define PinDefinitions_h

// Call library
#include <stdint.h>
#include <Servo.h>

/*
* Pin definitions for the motor controllers and other things hooked up to the output pins of the Arduino
*
* PINS MUST BE UPDATED AS PIN LAYOUT CHANGES!!
* IF NOT CHANGED NOTHING WILL WORK!!
*/
constexpr uint8_t LEFT_MOTOR = 4;        // This is the pin for the left motors
constexpr uint8_t RIGHT_MOTOR = 11;      // This is the pin for the right motors

constexpr uint8_t DIGGING_MOTOR = 6;
constexpr uint8_t DIGGING_ACTUATOR = 10;

constexpr uint8_t DEPOSIT_MOTOR = 5;
constexpr uint8_t DEPOSIT_VIBRATOR = 9;

constexpr uint8_t HORIZONTAL_SERVO = 7;
constexpr uint8_t VERTICAL_SERVO = 8;
constexpr uint8_t ARM_SERVO = 13;

constexpr uint8_t FRONT_RIGHT_WHEEL_ENCODER_PIN1 = 2;
constexpr uint8_t FRONT_RIGHT_WHEEL_ENCODER_PIN2 = 3;
constexpr uint8_t FRONT_LEFT_WHEEL_ENCODER_PIN1 = NULL;
constexpr uint8_t FRONT_LEFT_WHEEL_ENCODER_PIN2 = NULL;
constexpr uint8_t REAR_RIGHT_ENCODER_PIN1 = NULL;
constexpr uint8_t REAR_RIGHT_ENCODER_PIN2 = NULL;
constexpr uint8_t REAR_LEFT_ENCODER_PIN1 = NULL;
constexpr uint8_t REAR_LEFT_ENCODER_PIN2 = NULL;

#endif //PinDefinitions_h
