# Task 6.2

---

1. I defined the pins for A, B.

```arduino
#define PIN_ENCODER_A 6
#define PIN_ENCODER_B 7
```

1. Function called when Signal A changes. If signal A is not the same as signal B, then the motor is moving clockwise, else then the motor is moving counter clockwise.

```arduino
void ISR_encoderPinA();
```

1. Function called when Signal B changes. If signal B is the same as signal A, then the motor is moving clockwise, else then the motor is moving counter clockwise.

```arduino
void ISR_encoderPinB();
```

> You can find the full code at ***task6_2.ino***
> 

---

# Problem:

Statement: 

- We need to design a Software Practical Low Pass Filter (LPF) what is the proper cut off frequency (fc) If WALL-E has Specs:
    
    o Encoder has 540 pulse per revolution.
    
    o Track has three wheels only one motorized, with 40cm diameter.
    
    o Maximum speed of WALL-E 0.5 m/s.
    
    ---
    

**Answer:**

- Given:
    - pulsesPerRotation = 540 PPR.
    - maxSpeed = 0.5 m/s.
    - diameter = 40 cm = 0.4 m.
    
    → radius = 0.4/2 = 0.2m.
    
    $$
    \therefore\,rotationPerSecond = \frac{maxSpeed}{2*\pi*radius} =\frac{0.5}{2*\pi*0.2} = 0.397887 \,\,RPS
    $$
    
    $$
    \therefore \,pulsesPerSecond = rotationPerSecond * pulsePerRotation
    $$
    
    $$
    \therefore \,pulsePerSecond = 0.397887 *540=214.8592\;PPS
    $$
    
    ---
    
    - Proper cut off frequency should be higher than 215 Hz at least.
    - I would say the recommended cut off frequency = 220 Hz.
    
    ---