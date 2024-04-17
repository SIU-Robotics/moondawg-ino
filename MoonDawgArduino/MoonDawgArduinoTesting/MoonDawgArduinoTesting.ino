/*
 * This is the Arduino code for the MoonDawg rover.
 * The code is based off of last year's code, but modified to use the Servo library to control the motors instead of Serial communication.
 */
// Cameron Schwartzberg
// 2/18/2024, 7:07 PM
// 240216-212839-uno
// The main file that is loaded onto the Arduino, this will call all the functions needed to control the robot.
// Cameron Schwartzberg, Marco Caliendo, Andrew Barnes, Mitchell Wettig, Jared Hillyer

#include <Servo.h>
#include <Arduino.h>

#include "PinDefinitions.h"
#include "Movement.h"

constexpr int MAX_ARRAY_SIZE = 10;
constexpr int MAX_INPUT_LENGTH = 50;

constexpr char MOVEMENT = 'm';
constexpr char MOVEACT = 't';
constexpr char DIGBELT = 'b';
constexpr char DIGACT = 'g';
constexpr char DEPOSITAUGER = 'd';


// Class constructors
DriveMovement driving = DriveMovement();
DepositMovement depositing = DepositMovement();
DigMovement digging = DigMovement();

void commandProcessing(char* tokens[]) {

    char cmd = tokens[0][0];
    int param1 = atoi(tokens[1]);
    int param2;
    if (cmd == MOVEMENT) {
      param2 = atoi(tokens[2]);
    }
    else {
      param2 = (int)tokens[2][0];
    }


    switch (cmd) {
        case MOVEMENT:
            driving.drive(param1, param2);
            break;
        case MOVEACT:
            if (param1) {
                if (param2 == 'l') {
                    driving.actuatorTurnLeft();
                }
                else if (param2 == 'r') {
                    driving.actuatorTurnRight();
                }
            }
            else {
                driving.actuatorTurnStop();
            }
            break;
        case DIGBELT:
            if (param1) {
                if (param2 == 'f') {
                    digging.digMotorForward();
                }
                else if (param2 == 'b') {
                    digging.digMotorBackward();
                }
            }
            else {
                digging.digMotorStop();
            }
            break;
        case DIGACT:
            if (param1) {
                if (param2 == 'r')
                {
                    digging.digActuatorForward();
                }
                else if (param2 == 'l')
                {
                    digging.digActuatorBackward();
                }                
            }
            else {
                digging.digActuatorStop();
            }
            break;
        case DEPOSITAUGER:
            if (param1) {
                if (param2 == 'f') {
                    depositing.depositMotorForward();
                }
                else if (param2 == 'b')
                {
                    depositing.depositMotorBackward();
                }
                
            }
            else {
                depositing.depositMotorStop();
            }
            break;
        default:
            break;
    }
}


void setup() {
  // put your setup code here, to run once:
    // For the serial communication from RPi to Arduino
    Serial.begin(9600);

    driving.driveSetup(LEFT_MOTOR, RIGHT_MOTOR);
    depositing.depositSetup(DEPOSIT_MOTOR, DEPOSIT_VIBRATOR);
    digging.digSetup(DIGGING_MOTOR, DIGGING_ACTUATOR);
}

void loop() {
  // put your main code here, to run repeatedly

    if (Serial.available() > 0) {
        char inputBuffer[MAX_INPUT_LENGTH + 1] = {0}; // +1 for null terminator

        // Read bytes directly into the buffer
        int bytesRead = Serial.readBytesUntil('\n', inputBuffer, MAX_INPUT_LENGTH);
        inputBuffer[bytesRead] = '\0'; // Add null terminator

        char* tokens[3];

        int numCount = 0;
        char *token = strtok(inputBuffer, ",");

        while (token != NULL && numCount < MAX_ARRAY_SIZE) {
            tokens[numCount++] = token;
            token = strtok(NULL, ",");
        }

        commandProcessing(tokens);


    }
}

