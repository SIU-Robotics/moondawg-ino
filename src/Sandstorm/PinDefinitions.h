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
namespace pin
{
    // Drive motor pins
    constexpr uint8_t DRIVE_MOTOR_FL = 12;  // White
    constexpr uint8_t DRIVE_MOTOR_FR = 13;  // Blue
    constexpr uint8_t DRIVE_MOTOR_RL = 14;  // Yellow
    constexpr uint8_t DRIVE_MOTOR_RR = 15;  // Green
    constexpr uint8_t TURN_MOTOR_FL = 16;   // White
    constexpr uint8_t TURN_MOTOR_FR = 17;   // Blue
    constexpr uint8_t TURN_MOTOR_RL = 4;   // Yellow
    constexpr uint8_t TURN_MOTOR_RR = 19;   // Green
    constexpr uint8_t BELT_MOTOR = 21;      // Pin for the belt motor Orange
    constexpr uint8_t AUGER_MOTOR = 22;     // Pin for the auger motor Purple
    constexpr uint8_t L_ACTUATOR = 33;      // Pin for the left actuator Brown
    constexpr uint8_t R_ACTUATOR = 25;      // Pin for the right actuator Brown
    constexpr uint8_t VIBRATION_MOTOR = 27; // Pin for the vibration motor Red
    constexpr uint8_t CAMERA_YAW_SERVO = 32;
    constexpr uint8_t CAMERA_PITCH_SERVO = 35;
}

#endif // PinDefinitions_h
