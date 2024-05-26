// Cameron Schwartzberg
// 2/18/2024, 7:07 PM
// 240216-212839-uno
// This holds all the pin definitions that the Arduino uses
// Cameron Schwartzberg, Marco Caliendo

#ifndef PinDefinitions_h
#define PinDefinitions_h

#include <stdint.h>

// Defining the pins for motor controllers
// These pins need to be updated to the correct pins

constexpr uint8_t LEFT_MOTOR = 3;        // This is the pin for the left motor controllers
constexpr uint8_t RIGHT_MOTOR = 11;    // This is the pin for the right motor controllers

constexpr uint8_t DIGGING_MOTOR = 6;
constexpr uint8_t DIGGING_ACTUATOR = 10;

constexpr uint8_t DEPOSIT_MOTOR = 5;
constexpr uint8_t DEPOSIT_VIBRATOR = 9;

constexpr uint8_t HORIZONTAL_SERVO = 7;
constexpr uint8_t VERTICAL_SERVO = 8;
constexpr uint8_t ARM_SERVO = 13;

#endif //PinDefinitions_h
