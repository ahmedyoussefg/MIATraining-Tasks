#include "pid_control.h"

// Defining the current value for the flow rate and target flow rate 
// This should be editted so that this variable recieves its input from the flow meter sensor 
double current_val = 0;
double target_val = 90;


// Creating an instance of PID Class
/*The K Parameters may need to be tuned */
PID pid_system(3,10,2,0.5);

void setup() {
  Serial.begin(9600);
}

void loop() {
  current_val = pid_system.pid_control(current_val, target_val);
  Serial.println(current_val);
  delay(pid_system.getDelay());
}