



#include "Communication.h"

namespace comm {
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
    * This processes the commands sent via the RPi into usuable function calls for the Arduino
    *
    * The function takes a parsed command converts that into two parameters and a command character
    * command is taken into the switch statement and compared to the defined command characters and will use that part of the switch statement
    * this is where either the command will take both params or will use param1 to decide if this is an 'ON' command, where param2
    * decides which of the 'ON' functions will be used.
    */
    void Process(char* tokens[], motors::Container motorContainer) {

        if (tokens[0] == nullptr || tokens[1] == nullptr) {
            return;
        }

        char cmd = tokens[0][0];
        int param1 = atoi(tokens[1]);
        int param2;
        if (tokens[2] != nullptr) {
            if (cmd == MOVEMENT || cmd == DIGBELT || cmd == HORIZONTAL || cmd == VERTICAL || cmd == ARM) {
            param2 = atoi(tokens[2]);
            }
            else {
            param2 = (int)tokens[2][0];
            }
        }

        switch (cmd) {
            case MOVEMENT:
                motors::drive(param1, param2, motorContainer.driveMotor1, motorContainer.driveMotor2);
                break;
            case DIGBELT:
                if (param1) {
                    motors::Set(motorContainer.digMotor, param2);
                }
                else {
                    motors::Stop(motorContainer.digMotor);
                }
                break;
            case DIGACT:
                if (param1) {
                    if (param2 == 'r')
                    {
                        motors::Forward(motorContainer.actuator);
                    }
                    else if (param2 == 'l')
                    {
                        motors::Backward(motorContainer.actuator);
                    }                
                }
                else {
                    motors::Stop(motorContainer.actuator);
                }
                break;
            case DEPOSITAUGER:
                if (param1) {
                    if (param2 == 'f') {
                        motors::Forward(motorContainer.auger);
                    }
                    else if (param2 == 'b')
                    {
                        motors::Backward(motorContainer.auger);
                    }
                    
                }
                else {
                    motors::Stop(motorContainer.auger);
                }
                break;
            case VIBRATOR:
                if (param1) {
                    if (param2 == 'v'){
                        motors::Forward(motorContainer.vibrator);
                    }
                }
                else {
                    motors::Stop(motorContainer.vibrator);
                }
                break;
            case HORIZONTAL:
                if (param1) {
                    motors::Set(motorContainer.horizontalServo, param2); // This is the function that will be called to move the horizontal servo
                }
                break;
            case VERTICAL:
                if (param1) {
                    motors::Set(motorContainer.verticalServo, param2); // This is the function that will be called to move the vertical servo
                }
                break;
            case ARM:
                if (param1) {
                    motors::Set(motorContainer.armServo, param2); // This is the function that will be called to move the arm servo
                }
                break;
            default:
                break;
        }
    }
}