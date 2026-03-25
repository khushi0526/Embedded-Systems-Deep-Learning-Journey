# Day 3 – PIR Motion Detection with Relay (Automatic Control System)

## Overview

This project demonstrates an automatic control system using a PIR (Passive Infrared) sensor and a relay. The system detects human motion and activates a connected device (simulated using a relay) based on detection.

The implementation focuses on understanding motion sensing and controlling higher-power devices through a microcontroller.

---

## Components Used

* PIR Motion Sensor
* Relay Module
* Arduino Uno
* Jumper Wires

---

## Simulation Link

https://wokwi.com/projects/459486738057118721

---

## Working Principle

The PIR sensor detects motion based on infrared radiation emitted by the human body.

* When no motion is present → sensor output remains LOW
* When motion is detected → sensor output becomes HIGH

The relay acts as a switch:

* It allows the microcontroller to control external devices safely
* It isolates low-power control from high-power circuits

---

## System Logic

* No motion → Relay OFF
* Motion detected → Relay ON
* System continuously monitors changes in motion

---

## Observations

* PIR sensor needs a few seconds to stabilize initially
* Motion detection is not continuous—it depends on movement
* Sensor range and angle affect detection
* Relay produces a clicking sound when switching

---

## Challenges

* Initial delay in PIR sensor response
* Understanding how relay works as a switch
* Avoiding false triggering due to small movements

---

## Improvements

* Add delay logic to keep relay ON for a few seconds after motion
* Combine with LDR for day/night-based automation
* Replace relay with transistor-based control for faster switching

---

## Learning Outcomes

* Understanding motion detection using PIR sensors
* Interfacing sensors with switching devices (relay)
* Basic automation system design
* Concept of controlling higher power loads using low-power signals

---

## Conclusion

This project demonstrates a simple automation system where motion detection is used to control a device. It introduces practical concepts used in real-world applications such as automatic lighting and security systems.
