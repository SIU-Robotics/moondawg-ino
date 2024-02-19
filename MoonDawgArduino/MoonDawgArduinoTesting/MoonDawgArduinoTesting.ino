#include <PinDefinitions.h>

#include <Movement.h>

#include <Setup.h>

#include <RoboClaw.h>

#include <Servo.h>




void setup() {
  // put your setup code here, to run once:
    // For the serial communication from RPi to Arduino
    Serial.begin(9600);

    driveMotorSetup driveMotor;
    driveMotor.driveSetup(LEFT_MOTOR, RIGHT_MOTOR);

    depositSetup depositMotor;
    depositMotor.depositMotorSetup(DEPOSIT_MOTOR);

    rumbleSetup rumbleMotor;
    rumbleMotor.rumbleMotorSetup(RUMBLE_MOTOR);

    digSetup digMotor;
    digMotor.digMotorSetup(DIGGING_MOTOR);

    digSetup digActuator;
    digActuator.digActuatorSetup(DIGGING_ACTUATOR);
}

void loop() {
  // put your main code here, to run repeatedly:

}
