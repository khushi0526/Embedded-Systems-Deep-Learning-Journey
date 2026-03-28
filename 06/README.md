# Day 6 – Finite State Machine (FSM) for Smart Lighting System

## Overview

Today, I introduced a Finite State Machine (FSM) to structure the smart lighting system. Instead of simply using immediate if-else conditions, the system tracks distinct states: "No Motion," "Motion Detected," and "Light ON," allowing smoother and clearer transitions between behaviors.

This approach mimics how real-world embedded systems manage complex behaviors.

---

## Components Used

* LDR (Light Dependent Resistor)
* PIR Motion Sensor
* LED
* Arduino Uno
* Resistor (10kΩ)

---

## Simulation Link

https://wokwi.com/projects/459760820023913473

---

## Working Principle

The FSM breaks the system down into states:

1. **IDLE**: No motion detected, LED OFF.
2. **MOTION_DETECTED**: Motion detected, LED turns ON if it is dark.
3. **LIGHT_ON**: LED remains ON for a set time even after motion stops.

Transitions between states happen based on input from both the LDR and PIR sensors.

---

## System Logic

* Start in **IDLE** state.
* If dark AND motion is detected → move to **MOTION_DETECTED**.
* After motion stops, start a timer → stay in **LIGHT_ON** state for a few seconds.
* After timer ends → return to **IDLE**.

This ensures that light stays on after motion, but only when needed.

---

## Component Deep Dive

**LDR**

* Measures ambient light continuously
* Used to decide if it’s dark or bright
* Analog output → used to determine threshold for darkness

**PIR Sensor**

* Detects motion based on infrared radiation
* Digital output (HIGH/LOW)
* Needs a few seconds to stabilize after power-up

**FSM Structure**

* FSM states: IDLE, MOTION_DETECTED, LIGHT_ON
* State transitions based on sensor inputs and time

---

## Observations

* The FSM ensures predictable system behavior
* LED stays on for a short time after motion stops, which feels more natural
* Transitions between states are smoother than immediate reaction
* The code is easier to modify since logic is broken down by states

---

## Challenges

* Ensuring correct timing for state transitions
* Managing sensor noise so transitions don’t “flicker”
* Properly initializing FSM state at startup

---

## Improvements

* Add variable timing (different delays based on day/night)
* Add an LED fade-in/fade-out effect for smoother user experience
* Use FSM for other embedded systems (e.g., door automation, HVAC control)

---

## Learning Outcomes

* How to implement a Finite State Machine in embedded systems
* Advantages of structured state management over simple if-else logic
* Combining multiple sensors with state-based decision-making
* Building more robust and predictable automation systems

---

## Conclusion

Today, I moved from a simple reactive system to a structured state machine approach. This helps ensure that the system responds consistently, and the logic can scale to handle more complex embedded applications.
