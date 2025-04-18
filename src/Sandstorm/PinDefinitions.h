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
    // I2C pins
    constexpr uint8_t I2C_SDA = 21;
    constexpr uint8_t I2C_SCL = 22;

#if defined(USE_DRIVE_SYSTEM) && defined(FRONT_LEFT)
    // Drive motor pins
    constexpr uint8_t I2C_ADDRESS = 0x10; // Pin for the drive motor
#elif defined(USE_DRIVE_SYSTEM) && defined(FRONT_RIGHT)
    // Drive motor pins
    constexpr uint8_t I2C_ADDRESS = 0x11; // Pin for the drive motor
#elif defined(USE_DRIVE_SYSTEM) && defined(REAR_LEFT)
    // Drive motor pins
    constexpr uint8_t I2C_ADDRESS = 0x12; // Pin for the drive motor
#elif defined(USE_DRIVE_SYSTEM) && defined(REAR_RIGHT)
    // Drive motor pins
    constexpr uint8_t I2C_ADDRESS = 0x13; // Pin for the drive motor
#elif defined(USE_TURN_SYSTEM)
    // Turn motor pins
    constexpr uint8_t I2C_ADDRESS = 0x14; // Pin for the turn motor
#elif defined(USE_DIGGING_SYSTEM)
    // Digging mechanism pins
    constexpr uint8_t I2C_ADDRESS = 0x20; // Pin for the digging motor
#elif defined(USE_DEPOSIT_SYSTEM)
    // Deposit system pins
    constexpr uint8_t I2C_ADDRESS = 0x21; // Pin for the deposit motor
#elif defined(USE_CAMERA_SYSTEM)
    // Camera servo pins
    constexpr uint8_t I2C_ADDRESS = 0x00; // Pin for the horizontal camera servo
#endif

#ifdef USE_DRIVE_SYSTEM
    // Drive motor pins
    constexpr uint8_t DRIVE_MOTOR = 0;
#endif

#ifdef USE_TURN_SYSTEM
    constexpr uint8_t TURN_MOTOR_FL = 0;
    constexpr uint8_t TURN_MOTOR_FR = 1;
    constexpr uint8_t TURN_MOTOR_RL = 2;
    constexpr uint8_t TURN_MOTOR_RR = 21;
#endif

#ifdef USE_DIGGING_SYSTEM
    // Digging mechanism pins
    constexpr uint8_t DIGGING_MOTOR = 0;    // Pin for the digging motor
    constexpr uint8_t DIGGING_ACTUATOR = 1; // Pin for the digging actuator
#endif

#ifdef USE_DEPOSIT_SYSTEM
    // Deposit system pins
    constexpr uint8_t DEPOSIT_MOTOR = 0;    // Pin for the deposit motor
    constexpr uint8_t DEPOSIT_VIBRATOR = 1; // Pin for the deposit vibrator
#endif

#ifdef USE_CAMERA_SYSTEM
    // Camera servo pins
    constexpr uint8_t HORIZONTAL_SERVO = 0; // Pin for the horizontal camera servo
    constexpr uint8_t VERTICAL_SERVO = 1;   // Pin for the vertical camera servo
    constexpr uint8_t ARM_SERVO = 2;        // Pin for the arm servo
#endif

#ifdef USE_ENCODER_SYSTEM
    // Encoder pins
    // Note: These are placeholder values and should be updated with the actual pin numbers
    constexpr uint8_t ENCODER_PIN1 = 2;
    constexpr uint8_t ENCODER_PIN2 = 3;
#endif
}

#endif // PinDefinitions_h
