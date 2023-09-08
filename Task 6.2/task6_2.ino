// Task 6.2:

#define PIN_ENCODER_A 6
#define PIN_ENCODER_B 7

long long counter = 0;

void ISR_encoderPinA() {
  if (digitalRead(PIN_ENCODER_A) != digitalRead(PIN_ENCODER_B)) {
    // moving clockwise
    counter++;
  } else {
    // moving counter-clockwise
    counter--;
  }
}

void ISR_encoderPinB() {
  if (digitalRead(PIN_ENCODER_B) == digitalRead(PIN_ENCODER_A)) {
    // moving clockwise
    counter++;
  } else {
    // moving counter-clockwise
    counter--;
  }
}

void setup() {
  // put your setup code here, to run once:

  // Encoder's Setup
  pinMode(PIN_ENCODER_A, INPUT_PULLUP);
  pinMode(PIN_ENCODER_B, INPUT_PULLUP);

  attachInterrupt(PIN_ENCODER_A, ISR_encoderPinA, CHANGE);
  attachInterrupt(PIN_ENCODER_B, ISR_encoderPinB, CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
}
