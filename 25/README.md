# Day 25 – Smart Room System with Manual Override

## Overview

This project enhances the smart room system by adding a manual override feature. The system can operate automatically based on sensors or be manually controlled by the user using a button.

---

## Components Used

* LDR
* DHT11
* Servo Motor
* LED
* Buzzer
* Push Button
* Arduino Uno

---

## Working Principle

* Button toggles between AUTO and MANUAL mode
* AUTO:

  * LDR → LED control
  * DHT → Servo + Buzzer
* MANUAL:

  * Button controls LED and Servo directly

---

## Working Principle

https://wokwi.com/projects/461118471516211201

---


## System Logic

### Mode Switching:

* Press button → toggle mode

### AUTO MODE:

* Dark → LED ON
* Temp controls servo
* High temp → buzzer

### MANUAL MODE:

* Button press → toggle LED
* Button press → toggle servo position

---

## Learning Outcomes

* Manual override systems
* Mode switching
* User + automation integration
* Real-world control logic

---

## Conclusion

This project demonstrates how automated systems can be overridden manually, a key feature in real-world applications.
