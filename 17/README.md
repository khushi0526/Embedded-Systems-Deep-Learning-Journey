# Day 17 – IR Sensor Object Detection System

## Overview

This project demonstrates object detection using an IR (Infrared) sensor. The system detects the presence of an object and activates an output (LED) accordingly.

IR sensors are widely used in obstacle detection, line-following robots, and automation systems.

---

## Components Used

* IR Sensor Module
* LED
* Arduino Uno
* Resistor (220Ω)

---

## Simulation Link

https://wokwi.com/projects/460536148693982209

---

## Working Principle

* IR sensor emits infrared light
* When an object is present, light reflects back
* Sensor detects reflection and outputs signal

Output:

* Object detected → LOW (in most modules)
* No object → HIGH

---

## System Logic

* Object detected → LED ON
* No object → LED OFF

---

## Component Deep Dive

**IR Sensor**

* Works using infrared reflection
* Provides digital output (HIGH/LOW)
* Fast response compared to ultrasonic
* Has adjustable sensitivity (potentiometer on module)

---

## Observations

* Very fast detection
* Sensitive to surface type and distance
* Works best at short range
* Output may invert (LOW = detected)

---

## Challenges

* Understanding inverted logic
* Adjusting sensitivity correctly
* Avoiding false detection

---

## Improvements

* Use buzzer instead of LED
* Combine with motor for obstacle avoidance
* Build line-following robot

---

## Learning Outcomes

* Understanding IR-based sensing
* Difference between distance and detection sensors
* Working with digital input signals
* Expanding sensor knowledge

---

## Conclusion

This project introduces IR sensing for object detection. It is widely used in robotics and automation due to its simplicity and fast response.
