# Day 5 – Smart Lighting with Delay (LDR + PIR + Timer Logic)

## Overview

This project extends the smart lighting system by adding time-based control. The LED turns ON when motion is detected in a dark environment and remains ON for a fixed duration even after motion stops.

This improves usability and mimics real-world automatic lighting systems.

---

## Components Used

* LDR (Light Dependent Resistor)
* PIR Motion Sensor
* LED
* Arduino Uno
* Resistor (220Ω)

---

## Simulation Link

https://wokwi.com/projects/459670397186279425
---

## Working Principle

The system uses:

* LDR → to detect light conditions
* PIR → to detect motion
* Timer logic → to maintain LED state

Instead of turning OFF immediately when motion stops, the system holds the output for a few seconds.

---

## System Logic

* If **dark AND motion detected** → LED ON
* Once ON → stays ON for few seconds
* After delay → LED turns OFF if no motion

---

## Component Deep Dive

**LDR**

* Provides analog values based on light
* Used for day/night detection

**PIR Sensor**

* Detects motion using infrared radiation
* Output is HIGH when motion is detected

---

## Observations

* System feels more natural compared to instant ON/OFF
* Delay improves usability
* Sensor readings still fluctuate slightly
* Timing plays an important role

---

## Challenges

* Managing timing without affecting system response
* Choosing proper delay duration
* Combining multiple conditions with time

---

## Improvements

* Use non-blocking timing (`millis()`)
* Add brightness control instead of simple ON/OFF
* Extend to control real appliances using relay

---

## Learning Outcomes

* Understanding time-based control in embedded systems
* Introduction to system “memory” behavior
* Improving user experience using delay logic
* Combining sensing, logic, and timing

---

## Conclusion

This project demonstrates how adding timing logic enhances system behavior, making it closer to real-world smart automation systems.
