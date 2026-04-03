# Day 13 – Smart Light System with LCD Display (Real-Time Status)

## Overview

This project enhances the smart lighting system by integrating an LCD display to show real-time system status. Instead of relying only on Serial Monitor, the system now provides direct visual feedback through hardware.

This makes the system more practical and closer to real-world embedded applications.

---

## Components Used

* PIR Motion Sensor
* LDR (Light Dependent Resistor)
* Relay Module
* Push Button
* LCD Display (16x2, I2C)
* Arduino Uno

---

## Simulation Link

https://wokwi.com/projects/460303600735387649

---

## Working Principle

The system operates as follows:

* Reads light level from LDR
* Detects motion using PIR
* Allows manual override using button
* Controls relay based on logic
* Displays system status on LCD

---

## LCD Display Output

The LCD shows:

**Line 1:** Mode + Light Status
**Line 2:** LDR value + Motion status

Example:
AUTO  Light:ON
LDR:420 M:1

---

## System Logic

* Same as Day 11 (Auto + Manual mode)
* Additional feature: Display system state on LCD

---

## Component Deep Dive

**LCD (16x2 I2C)**

* Displays 16 characters per line
* Uses I2C communication (only 2 pins: SDA, SCL)
* Reduces wiring complexity

**Why LCD is Important**

* Removes need for Serial Monitor
* Makes system standalone
* Improves user interaction

---

## Observations

* Real-time display improves usability
* Easy to debug system behavior
* LCD updates reflect sensor changes
* System feels like a real product

---

## Challenges

* Understanding I2C communication
* Managing display formatting
* Updating display without flicker

---

## Improvements

* Add custom messages (WELCOME, ALERT)
* Use OLED for better graphics
* Add icons or symbols

---

## Learning Outcomes

* Interfacing display modules
* Improving system usability
* Combining multiple hardware outputs
* Moving toward product-level design

---

## Conclusion

This project transforms the system into a user-friendly embedded application. By integrating an LCD display, the system becomes more interactive and practical for real-world use.
