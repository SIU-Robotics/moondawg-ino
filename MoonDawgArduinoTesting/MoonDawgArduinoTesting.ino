#include <RoboClaw.h>

#include <Servo.h>

// Defining the pins for motor controllers
#define LEFT 1
#define RIGHT 2

#define DIGGER 5
#define ACTUATOR 6

#define DEPOSIT 7

#define RUMBLE 8

// Classes for the rumble motor
class rumbleSetup {
  protected:
    Servo motor;
  public:
    void rumbleMotorSetup(int rumblePin);
};

// Setup for the rumble motor, will write 
void rumbleSetup::rumbleMotorSetup(int rumblePin){
  motor.attach(rumblePin);
  motor.write(90);
}


class depositSetup {
  protected:
    Servo motor;
  public:
    void depositMotorSetup(int depositPin);
};

void depositSetup::depositMotorSetup(int depositPin){
  motor.attach(depositPin);
  motor.write(90);
}


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


class driveMotorSetup{
  protected:
    Servo motor1;
    Servo motor2;
  public:
    void driveSetup(int leftPin, int rightPin);
};

void driveMotorSetup::driveSetup(int leftPin, int rightPin){
  motor1.attach(leftPin);
  motor2.attach(rightPin);
  //Set all motors to stop in setup
  motor1.write(90);
  motor2.write(90);
}

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

void driveMotorMovement::driveStraight(short int speed){
  motor1.write(speed);
  motor2.write(speed);
}

void driveMotorMovement::driveMedLeft(short int speed){
  motor1.write(speed);
  motor2.write(medTurn);
}

void driveMotorMovement::driveHardLeft(short int speed){
  motor1.write(speed);
  motor2.write(90);
}

void driveMotorMovement::driveMedRight(short int speed){
  motor1.write(medTurn);
  motor2.write(speed);
}

void driveMotorMovement::driveHardRight(short int speed){
  motor1.write(90);
  motor2.write(speed);
}



void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
