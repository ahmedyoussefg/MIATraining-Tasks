// Master Arduino
#include <Wire.h>

#define SLAVE_ADDRESS 9

int button_pin1 = 2; // Pin for the first push button
int button_pin2 = 7; // Pin for the second push button

void setup() {
  // put your setup code here, to run once:
  // Inputs:
  pinMode(button_pin1, INPUT);
  pinMode(button_pin2, INPUT);
  
  Wire.begin(); // Initialize I2C communication as master
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int button_state1 = digitalRead(button_pin1);
  int button_state2 = digitalRead(button_pin2);
  Wire.beginTransmission(SLAVE_ADDRESS); // Address of the receiver Arduino
  Wire.write(button_state1);  // Send the state of button 1
  Wire.write(button_state2);  // Send the state of button 2
  Wire.endTransmission();

  delay(100);
}
