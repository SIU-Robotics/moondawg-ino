#include <RoboClaw.h>

#include <Servo.h>


#define PWM_pin_Drive_Motor1 1
#define PWM_pin_Drive_Motor2 2

#define PWM_pin_Dig_Motor 5
#define PWM_pin_Dig_Actuator 6

#define PWM_pin_Deposit_Motor 7

#define PWM_pin_Rumble_Motor 8

RoboClaw roboclaw(&serial, 10000);
roboclaw.begin(38400);

class rumbleSetup {
  protected:
    Servo motor;
  public:
    void rumbleMotorSetup(PWM_pin_Rumble_Motor);
}

void rumbleMotorSetup(PWM_pin_Rumble_Motor){
  motor.attach(PWM_pin_Rumble_Motor);
  motor.write(90);
}


class depositSetup {
  protected:
    Servo motor;
  public:
    void depositMotorSetup(PWM_pin_Deposit_Motor);
}

void depositMotorSetup(PWM_pin_Deposit_Motor){
  motor.attach(PWM_pin_Dig_Motor);
  motor.write(90);
}


class digSetup {
  protected:
    Servo motor;

 public:
  void digMotorSetup(PWM_pin_Dig_Motor);
  void digActuatorSetup(PWM_pin_Dig_Actuator);
}

void digMotorSetup(PWM_pin_Dig_Motor){
  motor.attach(PWM_pin_Dig_Motor);
  motor.write(90);
}
void digActuatorSetup(PWM_pin_Dig_Actuator){

}


class driveMotorSetup{
  protected:
    Servo motor1;
    Servo motor2;
  public:
    void driveSetup(PWM_pin_Drive_Motor1, PWM_pin_Drive_Motor2);
};

void driveMotorSetup::driveSetup(PWM_pin_Drive_Motor1, PWM_pin_Drive_Motor2){
  motor1.attach(PWM_pin_Drive_Motor1);
  motor2.attach(PWM_pin_Drive_Motor2);
  //Set all motors to stop in setup
  motor1.write(90);
  motor2.write(90);
}

class driveMotorMovement : protected driveMotorSetup {
  private:
    float medTurn = ; // Equation for one side going slower than other
  public:
    void driveStraight(short int speed);
    void driveMedLeft(short int speed);
    void driveHardLeft(short int speed);
    void driveMedRight(short int speed);
    void driveHardRight(short int speed);
}

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

void driveHardRight(short int speed){
  motor1.write(90);
  motor2.write(speed);
}



void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
