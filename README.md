# NASA Lunabotics

NASA Lunabotics is a university-level competition challenging teams to design, build, and operate a lunar robot using NASA's systems engineering process. The competition simulates off-world terrain, requiring robots to traverse the environment and excavate simulated lunar material.

## moondawg-ino

This repository contains the ESP32 code for the SIU Lunabotics bot, specifically designed for the ESP-WROVER-KIT. The bot's control system is divided into two main components:

<details>
  <summary>Raspberry Pi - Master</summary>
  
  The Raspberry Pi acts as the master controller, managing the ESP32 and communicating with the user. It sends commands to the ESP32 via Serial communication. For more details on the Raspberry Pi side, see the moondawg-ros repository.
  
</details>

### ESP32 - Slave

#### Overview
  
The ESP32 processes commands sent from the Raspberry Pi and controls the bot's various functions. Currently, there is no feedback implemented, so all control is manual via user input.

##### Development Environment

This project uses PlatformIO, an extension for Visual Studio Code, instead of the Arduino IDE. This allows for more advanced project management and better support for the ESP32 platform.

##### File Structure

- **Sandstorm.cpp**: The main C++ file containing setup, loop, and serial communication handling.
- **PinDefinitions.h**: Defines pin assignments using ```constexpr uint8_t```.
- **Motors.h/Motors.cpp**: Contains functions for motor control and movement.
- **Communication.h/Communication.cpp**: Handles command processing from serial input.
- **Encoders.h**: Manages encoder functionality.

##### Sandstorm.cpp

This is the main C++ file that includes:
- Library inclusions
- Global variable declarations
- Setup function for initializing components
- Loop function for continuous operation and serial communication handling

#### PinDefinitions.h

Defines pin assignments using ```constexpr uint8_t``` for better type safety and compiler optimizations.

#### Motors.h/Motors.cpp

These files contain the functions that control the bot's movement and other motorized functions. The ```Setup``` function should be called in ```Sandstorm.cpp```'s ```setup()``` function.

#### Communication.h/Communication.cpp

These files handle the processing of commands received from the Raspberry Pi via serial communication. They interpret the commands and call the appropriate motor control functions.

#### Encoders.h

This file manages the encoder functionality, which is likely used for precise motor control and position tracking.

#### Adding New Functionality

To add new functionality, create new ```.h``` and ```.cpp``` files in the project directory, following the established format. Use PlatformIO's project management features to include these files in the build.

#### Dependencies

- ```ESP32Servo```: For servo motor control
- ```Arduino.h```: Standard Arduino functions (available in ESP32 core for Arduino)
- ```ESP32Encoder```: For encoder functionality

### Notes

- The project now uses an ESP32, specifically the ESP-WROVER-KIT, which offers more processing power and features compared to standard Arduino boards.
- PlatformIO is used for development, providing better project management and ESP32 support compared to the Arduino IDE.
- The camera control system previously used 360° servos, which caused interference issues. These have been replaced with 180° servos for better control and reliability.
- Future improvements could include exploring the use of stepper motors for more precise control.