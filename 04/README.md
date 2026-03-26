# Day 4 – Smart Lighting System (LDR + PIR)

## Overview

This project implements a smart lighting system by combining an LDR (light sensor) and a PIR (motion sensor). The system turns ON a light only when it is dark and motion is detected.

This reduces unnecessary power usage and mimics real-world automatic lighting systems.

---

## Components Used

* LDR (Light Dependent Resistor)
* PIR Motion Sensor
* LED
* Arduino Uno
* Resistor (10kΩ)

---

## Simulation Link

https://wokwi.com/projects/459579504788392961

---

## Working Principle

* LDR detects ambient light intensity
* PIR detects human motion

The system makes a decision based on both inputs:

* Light condition (bright/dark)
* Motion detection (present/absent)

---

## System Logic

* If **dark AND motion detected** → LED ON
* If **bright OR no motion** → LED OFF

This ensures the light only turns ON when actually needed.

---

## Component Deep Dive

**LDR**

* Resistance decreases with increase in light
* Used with voltage divider to generate analog signal
* Output varies continuously

**PIR Sensor**

* Detects changes in infrared radiation
* Outputs digital signal (HIGH/LOW)
* Requires stabilization time

---

## Observations

* System works only when both conditions are satisfied
* LDR values fluctuate slightly
* PIR detects motion with slight delay
* Combined logic improves efficiency

---

## Challenges

* Setting correct light threshold
* Synchronizing analog (LDR) and digital (PIR) inputs
* Handling unstable readings

---

## Improvements

* Add delay so light stays ON for some time
* Use PWM for brightness control
* Add calibration for different environments

---

## Learning Outcomes

* Combining multiple sensors in one system
* Implementing logical conditions (AND logic)
* Understanding real-world automation concepts
* Improving system efficiency using conditions

---

## Conclusion

This project demonstrates how multiple sensors can be combined to build an intelligent system. It reflects real-world applications such as automatic street lights and smart home lighting.
