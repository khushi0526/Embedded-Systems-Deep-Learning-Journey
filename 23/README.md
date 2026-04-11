# Day 23 – Manual and Automatic Control System (Servo + Button + DHT11)

## Overview

This project introduces dual-mode operation: Manual and Automatic control. The system can switch between user-controlled and sensor-based operation using a button.

This concept is widely used in industrial and smart systems.

---

## Components Used

* DHT11 Sensor
* Servo Motor
* Push Button
* Arduino Uno

---

## Working Principle

* Button toggles between modes
* Auto Mode:

  * Temperature controls servo
* Manual Mode:

  * Button press controls servo position
 
---

## Simulation Link

https://wokwi.com/projects/461013089866064897

---

## System Logic

* Press button → change mode
* Auto:

  * Temp < 28 → 0°
  * Temp ≥ 28 → 90°
* Manual:

  * Press button → toggle 0° / 90°

---

## Learning Outcomes

* Mode switching logic
* Button handling
* Multi-behavior systems
* Real-world control systems

---

## Conclusion

This project demonstrates flexible system design where both automatic and manual controls coexist.
