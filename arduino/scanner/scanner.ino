//PIE Mini Project 2: 3D Sensor Scanner 
//Author(s): Dasha Chadiuk, Max Stopyra, and Jacob Uy

#include <Servo.h>

//Pin Setup
#define IR A0
#define SERVO_PITCH 9
#define SERVO_YAW 10
#define START_BUTTON 12

int start_time = millis();
const int interval = 1000; 

//Servo Setup
Servo servo_pitch; 
Servo servo_yaw;

//Variables:
int servo_pitch_pos = 0; //vertical angle of sensor (degrees)
int servo_yaw_pos = 0; //horizonal angle of sensor (degrees)

int IR_clean; // Clean reading from IR sensor. 


void setup() {
  //Initialize pins:
  pinMode(IR, INPUT);
  pinMode(START_BUTTON, INPUT); 
  servo_pitch.attach(SERVO_PITCH); 
  servo_yaw.attach(SERVO_YAW); 

  Serial.begin(115200); //baud rate: 115200 bits per second
}

void loop() {

  delay(2500);
  
  //Sensor will read right to left for each 4 degree increase in the vertical angle. 
  for (servo_pitch_pos = 120; servo_pitch_pos >= 20; servo_pitch_pos-=4){
    servo_pitch.write(servo_pitch_pos);
    for (servo_yaw_pos = 60; servo_yaw_pos <= 160; servo_yaw_pos+=4){
      servo_yaw.write(servo_yaw_pos);
      delay(100);
      if (it_is_time(millis(), start_time, interval)){
//        Serial.print("");
        Serial.print(clean_reading(analogRead(IR), analogRead(IR), analogRead(IR))); //IR sensor data given the two angles. 
        Serial.print(",");
        Serial.print(servo_pitch_pos); //vertical angle in degrees
        Serial.print(",");
        Serial.println(servo_yaw_pos); //horizonal angle in degrees
        delay(100);
      }
    }
  }    
}




bool it_is_time(uint32_t t, uint32_t t0, uint32_t dt){
  /*
   Checks to ensure that the chosen time interval has passed. 
   Args:
    t: current time in milliseconds
    t0: start time of the program in milliseconds. 
    dt: chosen time interval in milliseconds. 
   Returns True or False. 
  */
  return ((t>= t0)&&(t-t0 >= dt))|| //normal case
         ((t<t0)&& (t+(-t0) >= dt)); //overflow case (when millis() gets set back to 0)
}

int clean_reading(int reading1, int reading2, int reading3){
  /*
  Takes three readings and finds the minimum of the three readings. 
  Returns:
    A clean reading from the IR sensor. 
  */
  return min(min(reading1, reading2), reading3);
}
