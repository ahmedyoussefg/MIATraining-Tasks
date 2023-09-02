// Slave Arduino
#include <Wire.h>

#define SLAVE_ADDRESS 9
const int ledPin = 9; // Pin for the LED

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT); // Set LED pin as output
  analogWrite(ledPin, 0);  // Start with LED off
  Wire.begin(SLAVE_ADDRESS);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
}
void receiveEvent(int bytes) {
  if (bytes >= 2) // two buttons states are recieved
  {
    int button_state1 = Wire.read(); // Read the state of button 1
    int button_state2 = Wire.read(); // Read the state of button 2
    if (button_state1 == LOW && button_state2 == LOW) // 0 0
    {
      int brightness = 0;
      analogWrite(ledPin, brightness); // Set LED brightness
      Serial.println("No message");
    }
    else if (button_state1 == LOW && button_state2 == HIGH) // 0 1
    {
      int brightness = 191; // 75% of 255
      analogWrite(ledPin, brightness); // Set LED brightness
      Serial.println("Vector distracted");
    }
    else if (button_state1 == HIGH && button_state2 == LOW) // 1 0
    {
      int brightness = 127; // 50% of 255
      analogWrite(ledPin, brightness); // Set LED brightness
      Serial.println("Vector focused");
    }
    else if (button_state1 == HIGH && button_state2 == HIGH) // 1 1
    {
      int brightness = 255; // 100% of 255
      analogWrite(ledPin, brightness); // Set LED brightness
      Serial.println("Glitch");
    }
  }
}
void loop() {
  // put your main code here, to run repeatedly:
}
