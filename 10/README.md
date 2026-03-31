# Day 10 – Smart Automatic Light (PIR + LDR + Relay)

## Overview

This project implements a smart automatic lighting system using both motion detection and ambient light sensing. The system turns ON a light only when it is dark and motion is detected, using a relay to simulate control of a real-world device.

This combines multiple sensors and control logic to create an efficient and practical embedded system.

---

## Components Used

* PIR Motion Sensor
* LDR (Light Dependent Resistor)
* Relay Module
* Arduino Uno
* Resistor (10kΩ for LDR, 220Ω for LED if used)

---

## Simulation Link

https://wokwi.com/projects/460033019428491265

---

## Working Principle

The system uses two inputs:

* **LDR** → detects whether it is day or night
* **PIR** → detects motion

The relay is used to control the output device (light).

Only when both conditions are satisfied (dark + motion), the system activates the relay.

---

## System Logic

* If **dark AND motion detected** → Relay ON (light ON)
* If **bright OR no motion** → Relay OFF (light OFF)

This ensures energy-efficient operation.

---

## Component Deep Dive

**LDR**

* Provides analog values based on light intensity
* Used to determine day/night condition
* Requires threshold tuning

**PIR Sensor**

* Detects motion using infrared radiation
* Outputs digital signal
* Needs stabilization time

**Relay**

* Acts as a switch for external devices
* Provides isolation between microcontroller and load
* Works as ON/OFF control element

---

## Observations

* System works only when both conditions are satisfied
* Prevents unnecessary power usage during daytime
* Realistic behavior similar to smart lighting systems
* Relay switching introduces slight delay

---

## Challenges

* Selecting proper threshold for light detection
* Synchronizing analog (LDR) and digital (PIR) inputs
* Handling noise in LDR readings
* Understanding relay logic (active LOW behavior)

---

## Improvements

* Add delay to keep light ON after motion
* Apply filtering for stable LDR readings
* Use PWM for brightness control instead of ON/OFF
* Implement FSM for better structure

---

## Learning Outcomes

* Combining multiple sensors in a single system
* Designing condition-based automation
* Interfacing microcontroller with real-world devices
* Understanding energy-efficient system design

---

## Conclusion

This project demonstrates a complete embedded system integrating sensing, decision-making, and actuation. It reflects real-world smart lighting solutions used in homes, streets, and industrial automation.
