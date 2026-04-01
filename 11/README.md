# Day 11 – Smart Light with Manual Override (PIR + LDR + Relay + Button)

## Overview

This project enhances the smart automatic lighting system by adding a manual override feature using a push button. The system can operate in two modes:

* Automatic Mode → Controlled by sensors (LDR + PIR)
* Manual Mode → User directly controls the light

This improves usability and reflects real-world smart systems.

---

## Components Used

* PIR Motion Sensor
* LDR (Light Dependent Resistor)
* Relay Module
* Push Button
* Arduino Uno
* Resistors (10kΩ, 220Ω)

---

## Simulation Link

https://wokwi.com/projects/460079980089117697

---

## Working Principle

The system operates in two modes:

**Automatic Mode**

* Light turns ON only when it is dark and motion is detected

**Manual Mode**

* User can turn the light ON/OFF using a button
* Overrides sensor-based logic

---

## System Logic

* Button press → toggles mode (Auto ↔ Manual)

### In Auto Mode:

* Dark + Motion → Relay ON
* Otherwise → Relay OFF

### In Manual Mode:

* Button press → Toggle light ON/OFF

---

## Component Deep Dive

**Push Button**

* Digital input device
* Needs pull-up or pull-down resistor
* Used for user interaction

**LDR**

* Determines ambient light
* Provides analog values

**PIR Sensor**

* Detects motion
* Outputs digital signal

**Relay**

* Controls external device
* Works as a switch

---

## Observations

* Manual override gives better control
* Button needs proper handling to avoid multiple triggers
* System becomes more interactive
* Combines automation with user input

---

## Challenges

* Handling button debounce
* Managing two modes correctly
* Avoiding conflicts between manual and auto control

---

## Improvements

* Add LED indicator for mode (Auto/Manual)
* Use FSM to manage states clearly
* Add long-press detection for advanced control

---

## Learning Outcomes

* Adding user interaction to embedded systems
* Managing multiple modes of operation
* Understanding input handling (button logic)
* Designing flexible and user-friendly systems

---

## Conclusion

This project introduces human interaction into an automated system. It demonstrates how embedded systems can balance automation and manual control, which is essential in real-world applications.
