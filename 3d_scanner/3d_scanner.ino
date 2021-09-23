//PIE Mini Project 2: 3D Sensor Scanner 
//Author(s): Dasha Chadiuk, Max Stopyra, and Jacob Uy

#include <Servo.h>

//Pin Setup
int IRSensor = A0; 
int servo1Pin = A1;
int servo2Pin = A2;  
int outputValue = 0; 

//Servo Setup
Servo servo1; 
Servo servo2;

//Variables:
int servo1Position = 0; 
int servo2Position = 0; 

int sensorOutput; 


void setup() {
  //Initialize pins:
  pinMode(IRSensor, INPUT); 
  servo1.attach(servo1Pin); 
  servo2.attach(servo2Pin); 

  Serial.begin(9600); //baud rate: 9600 bits per second
}

void loop() {
  //Testing that servos work by rotating them 180 degrees 
//  for (servo1Position = 0; servo1Position <= 180; servo1Position++){
//    servo1.write(servo1Position); 
//    delay(10);
//  }
//  for (servo2Position = 0; servo2Position <= 180; servo2Position++){
//    servo2.write(servo2Position); 
//    delay(10);
//  }

  //Testing that IR sensor works:
  sensorOutput = analogRead(IRSensor);
  outputValue = map(sensorOutput, 0, 1023, 1.8, 2.3);  
  Serial.println(outputValue); 
  delay(500); 
}
