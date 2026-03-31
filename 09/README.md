# Day 9 – Automatic Room Light (PIR + Relay System)

## Overview

This project implements an automatic room lighting system using a PIR sensor and a relay. The system detects human motion and controls a light (represented using a relay) automatically.

This is a practical real-world application commonly used in smart homes and energy-efficient systems.

---

## Components Used

* PIR Motion Sensor
* Relay Module
* Arduino Uno
* LED (as load simulation)
* Resistor (220Ω)

---

## Simulation Link

https://wokwi.com/projects/460020237647054849

---

## Working Principle

* PIR sensor detects motion based on infrared radiation
* When motion is detected, it sends a HIGH signal
* The Arduino processes this signal
* The relay is activated to turn ON the connected load

---

## System Logic

* Motion detected → Relay ON (light ON)
* No motion → Relay OFF (light OFF)

---

## Component Deep Dive

**PIR Sensor**

* Detects changes in infrared radiation
* Output is digital (HIGH/LOW)
* Requires stabilization time

**Relay**

* Works as an electrically controlled switch
* Allows control of external devices
* Provides isolation between control and load

---

## Observations

* Relay produces clicking sound when switching
* PIR detection depends on movement
* System responds in real-time
* Works similar to automatic room lights

---

## Challenges

* Initial delay due to PIR stabilization
* Handling false triggers
* Understanding relay wiring (COM, NO, NC)

---

## Improvements

* Add delay to keep light ON for some time
* Combine with LDR for day/night control
* Use FSM for better system behavior

---

## Learning Outcomes

* Building a real-world automation system
* Interfacing sensors with high-power control devices
* Understanding practical applications of embedded systems
* Integrating sensing, processing, and actuation

---

## Conclusion

This project demonstrates a complete embedded system where sensing, decision-making, and real-world control are integrated. It reflects practical smart lighting solutions used in homes and industries.
