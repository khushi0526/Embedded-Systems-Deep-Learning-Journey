# Day 1 – LDR Based Light Control

## Overview

Today I worked on understanding how an LDR (Light Dependent Resistor) behaves and how it can be used to control an LED based on light intensity.

I implemented two versions:

1. Basic ON/OFF control
2. LED brightness control using PWM

---

## Simulation Links

Basic ON/OFF:
https://wokwi.com/projects/459366528384393217

Brightness Control:
https://wokwi.com/projects/459367279875913729

---

## Components Used

* LDR
* 10kΩ Resistor
* LED
* Arduino Uno

---

## Working Concept

The LDR changes its resistance based on light:

* In bright light → resistance decreases
* In darkness → resistance increases

Using a voltage divider, this change is converted into a voltage which is read by the Arduino using an analog pin.

---

## Implementation

### 1. Basic ON/OFF

* If light is low → LED turns ON
* If light is high → LED turns OFF

### 2. Brightness Control

* LED brightness changes based on light intensity
* Used PWM (`analogWrite`) for smooth variation
* Dark → brighter LED
* Bright → dim LED

---

## Observations

* LDR readings are not constant and fluctuate slightly
* Choosing threshold value is important
* PWM gives smoother and more practical output compared to ON/OFF

---

## What I Learned

* How to read analog values using Arduino
* How voltage divider works in real circuits
* Difference between digital control and analog control
* How to map sensor values to output

---

## Conclusion

This project helped me understand how a simple sensor can be used to build a practical system and how improving logic (ON/OFF → PWM) makes the system more efficient and realistic.
