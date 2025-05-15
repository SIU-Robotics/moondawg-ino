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

#ifdef USE_DRIVE_SYSTEM
    // Drive motor pins
    constexpr uint8_t DRIVE_MOTOR_FL = 12;
    constexpr uint8_t DRIVE_MOTOR_FR = 13;
    constexpr uint8_t DRIVE_MOTOR_RL = 14;
    constexpr uint8_t DRIVE_MOTOR_RR = 15;
    constexpr uint8_t TURN_MOTOR_FL = 16; // GREEN
    constexpr uint8_t TURN_MOTOR_FR = 17; // BLUE
    constexpr uint8_t TURN_MOTOR_RL = 18; // YELLOW
    constexpr uint8_t TURN_MOTOR_RR = 19; // RED
#endif

#ifdef USE_EXCAVATION_SYSTEM
    // Excavation system pins
    constexpr uint8_t BELT_MOTOR = 12;      // Pin for the belt motor
    constexpr uint8_t AUGER_MOTOR = 13;     // Pin for the auger motor
    constexpr uint8_t L_ACTUATOR = 14;      // Pin for the left actuator
    constexpr uint8_t R_ACTUATOR = 15;      // Pin for the right actuator
    constexpr uint8_t VIBRATION_MOTOR = 16; // Pin for the vibration motor
#endif

#ifdef USE_DIGGING_SYSTEM
    // Digging mechanism pins
    constexpr uint8_t DIGGING_MOTOR = 2;      // Pin for the digging motor
    constexpr uint8_t DIGGING_RACTUATOR = 17; // Pin for the digging actuator
    constexpr uint8_t DIGGING_LACTUATOR = 18; // Pin for the digging actuator
#endif

#ifdef USE_DEPOSIT_SYSTEM
    // Deposit system pins
    constexpr uint8_t DEPOSIT_MOTOR = 2;     // Pin for the deposit motor
    constexpr uint8_t DEPOSIT_VIBRATOR = 17; // Pin for the deposit vibrator
#endif

#ifdef USE_CAMERA_SYSTEM
    // Camera servo pins
    constexpr uint8_t HORIZONTAL_SERVO = 2; // Pin for the horizontal camera servo
    constexpr uint8_t VERTICAL_SERVO = 17;  // Pin for the vertical camera servo
#endif

#ifdef USE_ENCODER_SYSTEM
    // Encoder pins
    // Note: These are placeholder values and should be updated with the actual pin numbers
    constexpr uint8_t ENCODER_PIN1 = 18;
    constexpr uint8_t ENCODER_PIN2 = 19;
#endif
}

#endif // PinDefinitions_h
