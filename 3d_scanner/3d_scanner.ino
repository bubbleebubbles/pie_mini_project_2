//PIE Mini Project 2: 3D Sensor Scanner 
//Author(s): Dasha Chadiuk, Max Stopyra, and Jacob Uy

#include <Servo.h>

//Pin Setup
const uint8_t IRSensor = A0; 
const uint8_t servo1Pin = A1;
const uint8_t servo2Pin = A2;  
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

  Serial.begin(115200); //baud rate: 115200 bits per second
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
  Serial.println(outputValue); 
  delay(500); 
}
