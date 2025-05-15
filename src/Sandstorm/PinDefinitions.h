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

#if defined(USE_DRIVE_SYSTEM)
    // Drive motor pins
    constexpr uint8_t I2C_ADDRESS = 0x10; // Pin for the drive motor
#elif defined(USE_EXCAVATION_SYSTEM)
    // Excavation system pins
    constexpr uint8_t I2C_ADDRESS = 0x11; // Pin for the excavation system
#endif

#if defined(USE_DRIVE_SYSTEM)
    // Drive motor pins
    constexpr uint8_t DRIVE_MOTOR_FL = 12;
    constexpr uint8_t DRIVE_MOTOR_FR = 13;
    constexpr uint8_t DRIVE_MOTOR_RL = 14;
    constexpr uint8_t DRIVE_MOTOR_RR = 15;
    constexpr uint8_t TURN_MOTOR_FL = 16; // GREEN
    constexpr uint8_t TURN_MOTOR_FR = 17; // BLUE
    constexpr uint8_t TURN_MOTOR_RL = 18; // YELLOW
    constexpr uint8_t TURN_MOTOR_RR = 19; // RED
#elif defined(USE_EXCAVATION_SYSTEM)
    // Excavation system pins
    constexpr uint8_t BELT_MOTOR = 12;      // Pin for the belt motor
    constexpr uint8_t AUGER_MOTOR = 13;     // Pin for the auger motor
    constexpr uint8_t L_ACTUATOR = 14;      // Pin for the left actuator
    constexpr uint8_t R_ACTUATOR = 15;      // Pin for the right actuator
    constexpr uint8_t VIBRATION_MOTOR = 16; // Pin for the vibration motor
#endif
}

#endif // PinDefinitions_h
