# Day 15 – Servo Control Using Potentiometer (Analog Input System)

## Overview

This project demonstrates controlling a servo motor using a potentiometer. The potentiometer provides an analog input, which is mapped to the servo’s angle, allowing real-time manual control.

This introduces the concept of analog input-based actuation.

---

## Components Used

* Servo Motor (SG90)
* Potentiometer
* Arduino Uno
* Jumper Wires

---

## Simulation Link

https://wokwi.com/projects/460444791818413057

---

## Working Principle

* Potentiometer provides an analog value (0–1023)
* Arduino reads this value using `analogRead()`
* The value is mapped to servo angle (0°–180°)
* Servo rotates according to knob position

---

## System Logic

* Read potentiometer value
* Convert (map) value to angle
* Send angle to servo
* Servo moves in real time

---

## Component Deep Dive

**Potentiometer**

* Variable resistor
* Provides analog voltage output
* Used for manual control

**Servo Motor**

* Controlled using PWM signals
* Moves to specific angles
* Used in robotics and automation

---

## Observations

* Smooth real-time control of servo
* Small knob movement changes angle
* System feels interactive
* Analog input gives continuous control

---

## Challenges

* Mapping values correctly
* Avoiding jitter in servo movement
* Stable wiring for analog input

---

## Improvements

* Add display to show angle
* Add limits for safe movement
* Combine with sensor for automatic + manual control

---

## Learning Outcomes

* Understanding analog input
* Mapping values between ranges
* Real-time control systems
* Human-machine interaction

---

## Conclusion

This project demonstrates how analog input can be used to control actuators dynamically. It forms the basis for many real-world control systems.
