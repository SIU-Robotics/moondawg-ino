/*
 * This is the Arduino testing code for the MoonDawg rover.
 * This code will be used to test the functionality and viability of the final rover code.
 * The code is based off of last year's code, but modified to use the Servo library to control the motors instead of Serial communication.
 */
// Cameron Schwartzberg
// 2/18/2024, 7:07 PM
// 240216-212839-uno
// (Description)
// (Contributors)

#include <Servo.h>
#include <Arduino.h>

#include "PinDefinitions.h"
#include "Movement.h"

constexpr int MAX_ARRAY_SIZE = 10;
constexpr int MAX_INPUT_LENGTH = 20;

constexpr uint8_t MOVEMENT = 1;
constexpr uint8_t MOVEACTLEFT = 2;
constexpr uint8_t MOVEACTRIGHT = 3;
constexpr uint8_t MOVEACTSTOP = 4;
constexpr uint8_t DIGMOTORFORWARDAND = 5;
constexpr uint8_t DIGMOTORBACKWARD = 6;
constexpr uint8_t DIGMOTORSTOP = 7;
constexpr uint8_t DIGACTFORWARD = 8;
constexpr uint8_t DIGACTBACKWARD = 9;
constexpr uint8_t DIGACTSTOP = 10;
constexpr uint8_t DEPOSITMOTORFORWARD = 11;
constexpr uint8_t DEPOSITMOTORBACKWARD = 12;
constexpr uint8_t DEPOSITMOTORSTOP = 13;


// Class constructors
DriveMovement driving = DriveMovement();
DepositMovement depositing = DepositMovement();
DigMovement digging = DigMovement();

void commandProcessing(uint8_t cmd, int data1, int data2) {
    if(cmd == MOVEMENT) {
        driving.drive(data1, data2);
    }
    if(cmd == MOVEACTLEFT) {
        driving.actuatorTurnLeft();
    }
    if(cmd == MOVEACTRIGHT) {
        driving.actuatorTurnRight();
    }
    if(cmd == MOVEACTSTOP) {
        driving.actuatorTurnStop();
    }
    if(cmd == DIGMOTORFORWARDAND) {
        digging.digMotorForward();
    }
    if(cmd == DIGMOTORBACKWARD) {
        digging.digMotorBackward();
    }
    if(cmd == DIGMOTORSTOP) {
        digging.digMotorStop();
    }
    if(cmd == DIGACTFORWARD) {
        digging.digActuatorForward();
    }
    if(cmd == DIGACTBACKWARD) {
        digging.digActuatorBackward();
    }
    if(cmd == DIGACTSTOP) {
        digging.digActuatorStop();
    }
    if(cmd == DEPOSITMOTORFORWARD) {
        depositing.depositMotorForward();
    }
    if(cmd == DEPOSITMOTORBACKWARD) {
        depositing.depositMotorBackward();
    }
    if(cmd == DEPOSITMOTORSTOP) {
        depositing.depositMotorStop();
    }
}


bool hold = true;

void setup() {
  // put your setup code here, to run once:
    // For the serial communication from RPi to Arduino
    Serial.begin(9600);

    driving.driveSetup(LEFT_MOTOR, RIGHT_MOTOR, TURNING_ACTUATOR_ONE, TURNING_ACTUATOR_TWO);
    depositing.depositSetup(DEPOSIT_MOTOR);
    digging.digSetup(DIGGING_MOTOR, DIGGING_ACTUATOR_ONE, DIGGING_ACTUATOR_TWO);
}

void loop() {
  // put your main code here, to run repeatedly

    if (Serial.available() > 0) {
        char inputBuffer[MAX_INPUT_LENGTH + 1] = {0}; // +1 for null terminator

        // Read bytes directly into the buffer
        int bytesRead = Serial.readBytesUntil('\n', inputBuffer, MAX_INPUT_LENGTH);
        inputBuffer[bytesRead] = '\0'; // Add null terminator

        // Tokenize and parse numbers
        char numbers[MAX_ARRAY_SIZE];
        int numCount = 0;
        char *token = strtok(inputBuffer, ",");

        while (token != NULL && numCount < MAX_ARRAY_SIZE) {
            numbers[numCount++] = atoi(token);
            token = strtok(NULL, ",");
        }



        }

        // Process your array of numbers
        /*for (int i = 0; i < numCount; i++) {
            Serial.print("Number ");
            Serial.print(i);
            Serial.print(": ");
            Serial.println(numbers[i]);
        }*/
    }

  driving.drive(120, 120);

  
}
