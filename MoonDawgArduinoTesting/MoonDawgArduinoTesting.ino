
#include <RoboClaw.h>

#include <Servo.h>

// Defining the pins for motor controllers
#define LEFT_MOTOR 1
#define RIGHT_MOTOR 2
#define TURNING_ACTUATOR 3

#define DIGGING_MOTOR 5
#define DIGGING_ACTUATOR 6

#define DEPOSIT_MOTOR 7

#define RUMBLE_MOTOR 8

// Class for the rumble motor setup
class rumbleSetup {
  protected:
    Servo motor;
  public:
    void rumbleMotorSetup(int rumblePin);
};

// Setup for the rumble motor, will write to 90 "stop"
void rumbleSetup::rumbleMotorSetup(int rumblePin){
  motor.attach(rumblePin);
  motor.write(90);
}

// Class for the rumble motor movement
class rumbleMovement : protected rumbleSetup {
  public:
    void rumbleMotorForward();
    void rumbleMotorBackward();
    void rumbleMotorStop();
};

// Rumble motor movement, will write to the motor, 180 for forward, 0 for backward, 90 for stop
// We might not need both of these functions, but we'll test with both
void rumbleMovement::rumbleMotorForward(){
  motor.write(180);
}

void rumbleMovement::rumbleMotorBackward(){
  motor.write(0);
}

void rumbleMovement::rumbleMotorStop(){
  motor.write(90);
}


// Class for the deposit motor setup
class depositSetup {
  protected:
    Servo motor;
  public:
    void depositMotorSetup(int depositPin);
};

// Setup for the deposit motor, will write to 90 "stop"
void depositSetup::depositMotorSetup(int depositPin){
  motor.attach(depositPin);
  motor.write(90);
}

// Class for the deposit motor movement
class depositMovement : protected depositSetup {
  public:
    void depositMotorForward();
    void depositMotorBackward();
    void depositMotorStop();
};

// Deposit motor movement, will write to the motor, 180 for forward, 0 for backward, 90 for stop
void depositMovement::depositMotorForward(){
  motor.write(180);
}

void depositMovement::depositMotorBackward(){
  motor.write(0);
}

void depositMovement::depositMotorStop(){
  motor.write(90);
}


// Class for the dig motor setup
class digSetup {
  protected:
    Servo motor;

 public:
  void digMotorSetup(int diggerPin);
  void digActuatorSetup(int actuatorPin);
};

void digSetup::digMotorSetup(int diggerPin){
  motor.attach(diggerPin);
  motor.write(90);
}
void digSetup::digActuatorSetup(int actuatorPin){

}


// Class for the drive motor setup
class driveMotorSetup{
  protected:
    Servo motor1;
    Servo motor2;
  public:
    void driveSetup(int leftPin, int rightPin);
};

// Setup for the drive motor, will write to 90 "stop"
void driveMotorSetup::driveSetup(int leftPin, int rightPin){
  motor1.attach(leftPin);
  motor2.attach(rightPin);
  //Set all motors to stop in setup
  motor1.write(90);
  motor2.write(90);
}

// Class for the drive motor movement
class driveMotorMovement : protected driveMotorSetup {
  private:
    float medTurn = 0; // Equation for one side going slower than other
  public:
    void driveStraight(short int speed);
    void driveMedLeft(short int speed);
    void driveHardLeft(short int speed);
    void driveMedRight(short int speed);
    void driveHardRight(short int speed);
};

// Drive motor movement, will write to the motor
// Haven't decided where input will be taken from yet, once we get the info from what serial and data from that we will be receiving we can decide
// on how to implement the input, from the RPi which will take input from a controller
void driveMotorMovement::driveStraight(short int speed){
  motor1.write(speed);
  motor2.write(speed);
}

// Haven't made the formula for the medTurn yet, but we will need to make a formula for the medTurn
void driveMotorMovement::driveMedLeft(short int speed){
  motor1.write(speed);
  motor2.write(medTurn);
}

// Hard left turn, will write to the left motors to 90 "stop" and the right motor to the speed
void driveMotorMovement::driveHardLeft(short int speed){
  motor1.write(speed);
  motor2.write(90);
}

// Haven't made the formula for the medTurn yet, but we will need to make a formula for the medTurn
void driveMotorMovement::driveMedRight(short int speed){
  motor1.write(medTurn);
  motor2.write(speed);
}

// Hard right turn, will write to the right motors to 90 "stop" and the left motor to the speed
void driveMotorMovement::driveHardRight(short int speed){
  motor1.write(90);
  motor2.write(speed);
}



void setup() {
  // put your setup code here, to run once:
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
