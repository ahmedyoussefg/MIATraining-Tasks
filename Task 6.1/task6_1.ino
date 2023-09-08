// Task 6.1 :

#include <Wire.h>

#define IMU_ADDRESS 0x68
#define PWR_MGMT_1 0x6B

#define GYRO_CONFIG 0x1B
#define ZOUT_GYRO_H 0x47
#define GYRO_SENS 65.5

// getting current time
unsigned long long prev_time = millis();
// Initializing yaw angle by 0
double yawAngle = 0;

double readYawRate()
{
  int16_t data = 0;
  Wire.beginTransmission(IMU_ADDRESS);
  Wire.write(ZOUT_GYRO_H);
  Wire.endTransmission();

  Wire.requestFrom(IMU_ADDRESS, 2);

  while(Wire.available() < 2);

  data = Wire.read() << 8 | Wire.read();
  double yawRate = data * (double)GYRO_SENS;
  return yawRate;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.beginTransmission(IMU_ADDRESS);
  Wire.write(PWR_MGMT_1);
  Wire.write(0x00);
  Wire.endTransmission();
}

void loop() {
  // put your main code here, to run repeatedly:

  // Setting up Gyroscope Configuration
  Wire.beginTransmission(IMU_ADDRESS);
  Wire.write(GYRO_CONFIG);
  // set full scale range to +- 500 deg/s
  Wire.write(0x08);
  Wire.endTransmission();

  // Read the rate of change in yaw angle.
  double yawRate = readYawRate();
  
  // get Current Time
  unsigned long long curr_time = millis();
  
  // compute elapsed time
  double elapsed_time = curr_time - prev_time;
  elapsed_time *= 0.001; // from millis to seconds

  // Calculate angle by integrating the rate of change in yaw-angle in an interval of time
  yawAngle += yawRate * elapsed_time;
  Serial.println(yawAngle);
  delay(10);
  prev_time = millis();
}
