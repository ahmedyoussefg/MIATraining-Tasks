int NUM_SENSORS = 2;
// let the first sensor be checking left, the second sensor be checking down
int trigPins[NUM_SENSORS] = {2, 3}; // pin numbers for triggers sent
int echoPins[NUM_SENSORS] = {6, 7}; // pin numbers for echo returning
const double SPEED_OF_SOUND = 343.0; // Speed of sound in m/s

volatile unsigned long startTimes[NUM_SENSORS];
volatile unsigned long endTimes[NUM_SENSORS];

void setup() {
  Serial.begin(9600);
  
  for (int i = 0; i < NUM_SENSORS; i++) {
    pinMode(trigPins[i], OUTPUT);
    pinMode(echoPins[i], INPUT);
    attachInterrupt(digitalPinToInterrupt(echoPins[i]), echoInterrupt, CHANGE); // interrupt on change
  }
}

void loop() {
  // Trigger distance measurements
  for (int i = 0; i < NUM_SENSORS; i++) {
    digitalWrite(trigPins[i], HIGH);
    delay(40); //  40 ms  (maximum time for echo to return is (max(width,height)-1)*2/SPEED_OF_SOUND) which is nearly equal to 30 ms
    digitalWrite(trigPins[i], LOW);
  }
  
  delay(100);

  double x, y;
  
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    double distance;
    if(distanceReady[i])
    {
      unsigned long duration =  endTimes[i] - startTimes[i];
      distance = duration * SPEED_OF_SOUND / (40e-3); // divided by 40 ms
      distance /= 2; // because that was distance going forward and back
    }
    if (i == 0)
    {
      x = distance;
    }
    else
    {
      y = distance;
    }
  }
  Serial.print"X: ");
  Serial.println(x);
  Serial.print("Y: ";
  Serial.println(y);
  
  delay(1000);
}

void echoInterrupt() {
  for (int i = 0; i < NUM_SENSORS; i++) {
    if (digitalRead(echoPins[i]) == HIGH) {
      startTimes[i] = millis();
    } else {
      endTimes[i] = millis();
      distanceReady[i] = true; // distance ready for calculations
    }
  }
}