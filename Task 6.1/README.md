# Task 6.1

- I was required to interface with the famous and cheap IMU sensor

MPU6050 and retrieve the Yaw-angle (which is the angle along the z-axis). 

---

→ My approach was to read yaw rate and measure the elapsed time it took so we can get the change in yaw angle and add that change to the required value.

1. MPU6050 datasheet: [download link](https://pdf1.alldatasheet.com/datasheet-pdf/view/517743/ETC1/MPU-6000.html).
2. I used I2C connection so I had to include the library.

```arduino
#include <Wire.h>
```

1. I defined some macros that is going to be used in the program.

```arduino
#define IMU_ADDRESS 0x68
#define PWR_MGMT_1 0x6B
#define GYRO_CONFIG 0x1B
#define ZOUT_GYRO_H 0x47
#define GYRO_SENS 65.5

// The addresses of the registers are retrieved from the datasheet
// IMU_ADDRESS is the address register of the MPU6050
// PWR_MGMT_1 is the address register which allows the user to configure the power mode.
// GYRO_CONFIG allows the user to configure the gyroscope
// ZOUT_GYRO_H is the location of the high value of ZOUT in gyroscope measurements.
// GYRO_SENS : based on the full-scale range of the gyroscope, the FSR = +- 500 deg/
```

1. Initializing the variables:

```arduino
unsigned long long prev_time = millis();
double yawAngle = 0;
```

1. The function reads yaw angle’s rate of change

```arduino
double readYawRate();
```

> The rest of the code can be found in ***task6_1.ino***.
> 

---

# Question:

- **If the Sensor is surrounded by a noisy environment, what type of filter could used and what is the recommended cut off frequency depending on the sensor datasheet?**

→ If it was surrounded by noisy environment, we should use Low Pass Filter to remove high frequency noise from the signal and preserve the low frequency components in the signal. 

According to datasheet, we can configure DLPF (Digital Low Pass Filter) from DLPF_CONFIG value, which allows us to select the desired cut-off frequency. We could use DLPF_CONFIG = 3 ;

(equivalent to cut off frequency = 42Hz for Gyroscope and = 44Hz for Accelerometer). 

This would be a good choice, as it prevents a lot of noise signals and it doesn't cause much latency.

---