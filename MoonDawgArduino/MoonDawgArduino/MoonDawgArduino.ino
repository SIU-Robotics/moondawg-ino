/*
* This Arduino code is for Sandstorm the 2024 Lunabotics bot.
* The code has elements of the 2023 MoonDawg rover. However, has be heavily modified to abstract functions, use the Servo Library for control, 
* and use Serial for RPi -> Arduino communication.
* This main file is uploaded to the Arduino and will take the commands from the RPi and proccesses that into function calls.
* Owner: Cameron Schwartzberg
* Contributors: Marco Caliendo, Andrew Barnes, Mitchell Wettig, Jared Hillyer, and Joshua Greuel
* Date Created: 2/18/2024
*/

// Call all libraries
#include <Servo.h>
#include <Arduino.h>

/*
* PinDefinitions.h: This holds all of the pin definitions that can then be used to output signals.
* Movement.h: This holds the classes and functions that allow the bot to operated.
* Camera.h: This holds the class and functions for the camera to be able to move.
*/
#include "PinDefinitions.h"
#include "Movement.h"
#include "Camera.h"

// Creates the max array size and input length which is used to 
constexpr int MAX_ARRAY_SIZE = 10;
constexpr int MAX_INPUT_LENGTH = 50;

// This gives the definitions for what is being sent by the RPi to process into function commands.
constexpr char MOVEMENT = 'm';
constexpr char DIGBELT = 'b';
constexpr char DIGACT = 'g';
constexpr char DEPOSITAUGER = 'd';
constexpr char VIBRATOR = 'v';
constexpr char HORIZONTAL = 'h';
constexpr char VERTICAL = 'e';
constexpr char ARM = 'a';


/* 
* Class constructors
* Default constructors are required without arguments here, as initializing motors will cause it to break.
* CANNOT HOUSE ANY OF THE SETUP CODE!!
*/
DriveMovement driving = DriveMovement();
DepositMovement depositing = DepositMovement();
DigMovement digging = DigMovement();
CameraControl camera = CameraControl();

/*
* This processes the commands sent via the RPi into usuable function calls for the Arduino
*
* The function takes a parsed command converts that into two parameters and a command character
* command is taken into the switch statement and compared to the defined command characters and will use that part of the switch statement
* this is where either the command will take both params or will use param1 to decide if this is an 'ON' command, where param2
* decides which of the 'ON' functions will be used.
*/
void commandProcessing(char* tokens[]) {

    char cmd = tokens[0][0];
    int param1 = atoi(tokens[1]);
    int param2;
    if (cmd == MOVEMENT || cmd == DIGBELT || cmd == HORIZONTAL || cmd == VERTICAL || cmd == ARM) {
      param2 = atoi(tokens[2]);
    }
    else {
      param2 = (int)tokens[2][0];
    }


    switch (cmd) {
        case MOVEMENT:
            driving.drive(param1, param2);
            break;
        case DIGBELT:
            if (param1) {
                digging.digMotor(param2);
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
        case VIBRATOR:
            if (param1) {
                if (param2 == 'v'){
                    depositing.depositVibrator();
                }
            }
            else {
                depositing.depositVibratorStop();
            }
            break;
        case HORIZONTAL:
            if (param1) {
                camera.moveHorizontal(param2);
            }
            break;
        case VERTICAL:
            if (param1) {
                camera.moveVertical(param2);
            }
            break;
        case ARM:
            if (param1) {
                camera.moveArmHold(param2);
            }
            break;
        default:
            break;
    }
}


void setup() {
    // For the serial communication from RPi to Arduino
    Serial.begin(9600);
    
    // This is how the constructor is able to setup all of the code in each of the classes
    driving.driveSetup(LEFT_MOTOR, RIGHT_MOTOR);
    depositing.depositSetup(DEPOSIT_MOTOR, DEPOSIT_VIBRATOR);
    digging.digSetup(DIGGING_MOTOR, DIGGING_ACTUATOR);
    camera.cameraSetup(HORIZONTAL_SERVO, VERTICAL_SERVO, ARM_SERVO);
}

void loop() {

    // This parses the data sent from the RPi
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

