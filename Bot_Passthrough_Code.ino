// Include the servo library
#include <Servo.h>

// Define Input Connections
#define turningChannel 11
#define forwardChannel 10
#define actuatorChannel 9

// Define Output Connections
#define leftSteer 2
#define rightSteer 4
#define leftWheels 6
#define rightWheels 5

// Creates servo objects for each wheel
Servo moveLeftWheels;
Servo moveRightWheels;
 
// Integers to represent values from sticks and pots
int actuatorValue; 
 
// Read the number of a specified channel and convert to the range provided.
// If the channel is off, return the default value
int readChannel(int channelInput, int minLimit, int maxLimit, int defaultValue){
  int ch = pulseIn(channelInput, HIGH, 30000);
  if (ch < 100) return defaultValue;
  return map(ch, 1000, 2000, minLimit, maxLimit);
}

// Controls the Left and Right wheels based on PWM inputs from the Remote Controller
void controllerMotion(){
  int x = readChannel(forwardChannel, -90, 90, 0);
  int y = readChannel(turningChannel, -90, 90, 0);
  int left = y + x;
  int right = y - x;
  moveLeftWheels.write(left + 90);
  moveRightWheels.write(right + 90);
}

// Controls the turning actuator based on pwm inputs from RC controller
void controllerSteering(){
  actuatorValue = readChannel(actuatorChannel, 0, 180, 90);
  if(actuatorValue > 100){
    steering("Left");
  }
  else if(actuatorValue < 80){ 
    steering("Right");     
  }
  else {
    steering("Stop");
  }
}

// Controls the steering actuator
// Takes three different string commands: Left, Right, and Stop
// Example steering("Left") will turn the actuator left
void steering(String command){
  if(command == "Left"){
    digitalWrite(rightSteer, LOW);
    digitalWrite(leftSteer, HIGH);  
  }
  if(command == "Right"){
    digitalWrite(leftSteer, LOW);
    digitalWrite(rightSteer, HIGH); 
  }
  if(command == "Stop"){
    digitalWrite(leftSteer, LOW);
    digitalWrite(rightSteer, LOW);
  }
}

void setup(){
  pinMode(actuatorChannel, INPUT);      // PWM input from remote controller for steering actuator
  pinMode(leftSteer, OUTPUT);           // utput pin for turning left on the steering actuator
  pinMode(rightSteer, OUTPUT);          // Output pin for turning right on the steering actuator
  moveLeftWheels.attach(leftWheels);    // PWM output for the left side driving wheels to motor controller
  moveRightWheels.attach(rightWheels);  // PWM output for the right side driving wheels to motor controller
}
 
void loop() {
  controllerSteering();
  controllerMotion();
}