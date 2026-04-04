# Day 14 – Servo Motor Control (Position-Based Actuation)

## Overview

This project introduces servo motor control using Arduino. Unlike simple ON/OFF devices, a servo motor allows precise control of angular position, making it useful for robotics and automation systems.

The system demonstrates how to control servo position programmatically.

---

## Components Used

* Servo Motor (SG90)
* Arduino Uno
* Jumper Wires

---

## Simulation Link

https://wokwi.com/projects/460368102711041025

---

## Working Principle

A servo motor operates based on PWM (Pulse Width Modulation):

* Specific pulse signals correspond to specific angles
* Arduino sends PWM signals to control position
* Servo rotates to the commanded angle

---

## System Logic

* Rotate servo to 0°
* Move to 90°
* Move to 180°
* Repeat cycle

---

## Component Deep Dive

**Servo Motor**

* Controlled using PWM signals
* Rotates between 0° to 180°
* Has internal control circuit
* Provides precise positioning

---

## Observations

* Smooth movement between angles
* Limited rotation range (not continuous)
* Requires stable power supply
* More complex than LED/relay

---

## Challenges

* Understanding PWM concept
* Correct wiring (VCC, GND, Signal)
* Avoiding jitter in movement

---

## Improvements

* Control servo using potentiometer
* Combine with sensor (automatic door system)
* Add button-based position control

---

## Learning Outcomes

* Understanding PWM-based control
* Working with actuators beyond ON/OFF
* Learning position control systems
* Expanding embedded system knowledge

---

## Conclusion

This project introduces a new category of actuators that provide precise control. It is widely used in robotics, automation, and control systems.
