# Day 12 – System Status Display (Serial Monitoring Enhancement)

## Overview

This project enhances the smart lighting system by improving system visibility using Serial Monitor output. Instead of only controlling the relay, the system now clearly displays its internal state, sensor values, and mode of operation.

This helps in debugging, understanding system behavior, and improving reliability.

---

## Components Used

* PIR Motion Sensor
* LDR (Light Dependent Resistor)
* Relay Module
* Push Button
* Arduino Uno

---

## Simulation Link

https://wokwi.com/projects/460213155789034497

---

## Working Principle

The system continuously reads:

* LDR value (light level)
* PIR output (motion detection)
* Current mode (AUTO / MANUAL)
* Light state (ON / OFF)

All this information is displayed in a structured format using Serial Monitor.

---

## System Logic

* Same logic as Day 11 (Auto + Manual modes)
* Additional feature: detailed system feedback via Serial

---

## Serial Output Format

Example output:

Mode: AUTO | LDR: 420 | Motion: 1 | Light: ON
Mode: AUTO | LDR: 700 | Motion: 0 | Light: OFF

This provides real-time insight into system behavior.

---

## Component Deep Dive

**Serial Communication**

* Used for debugging and monitoring
* Helps track real-time system values
* Essential tool during development

---

## Observations

* Easier to understand why system behaves in a certain way
* Helps in tuning threshold values
* Useful for debugging sensor issues
* Improves confidence in system behavior

---

## Challenges

* Formatting output properly
* Avoiding too much data flooding
* Keeping delay balanced for readability

---

## Improvements

* Display data on LCD/OLED instead of Serial
* Add logging functionality
* Highlight warnings (e.g., unstable readings)

---

## Learning Outcomes

* Importance of system visibility
* Using Serial Monitor for debugging
* Understanding internal system states
* Improving development workflow

---

## Conclusion

This project emphasizes the importance of monitoring and debugging in embedded systems. By making system behavior visible, it becomes easier to understand, improve, and maintain the system.
