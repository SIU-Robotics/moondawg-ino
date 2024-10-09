#include <Encoder.h>

// Motor Connections
int enA = 9;
int in1 = 8;
int in2 = 7;
int input = A5;
int speed = 0;

int encoderPin1 = 2;
int encoderPin2 = 3;
Encoder enc(encoderPin1, encoderPin2);
long position = -999;
float rpm = 0.0;
unsigned long millisBefore;
float counts = 0.0;

void speedControl(){
  digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
  speed = analogRead(input);
  speed = map(speed, 0, 1023, 0, 255);
  analogWrite(enA, speed);
  //Serial.println(speed);
  delay(20);
}

void encoderFunction(){
  long counts;
  counts = enc.read();
  if (millis() - millisBefore > 1000){
    rpm = ((counts / 600.0) * 60.0) / 4;
    Serial.print("RPM: ");
    Serial.print(rpm);
    Serial.println();
    millisBefore = millis();
    enc.write(0);
  }

  // if a character is sent from the serial monitor,
  // reset both back to zero.
  if (Serial.available()) {
    Serial.read();
    Serial.println("Reset enc to zero");
    enc.write(0);
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
  pinMode(input, INPUT);

  digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  speedControl();
  encoderFunction();
}
