#define IR A0

int start_time = millis();
const int interval = 1000; 

int IR_clean; // Clean reading from IR sensor. 

void setup(){ 
  //Initialize pins:
  pinMode(IR, INPUT);
  Serial.begin(115200); //baud rate: 115200 bits per second
}

void loop() {
  if (it_is_time(millis(), start_time, interval)){
    Serial.print("IR Reading:");
    Serial.println(clean_reading(analogRead(IR), analogRead(IR), analogRead(IR))); //IR sensor data given the two angles. 
    delay(1000);
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
