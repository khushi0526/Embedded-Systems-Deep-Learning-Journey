# Day 22 – Smart Vent Control System (DHT22 + Servo + Buzzer)

## Overview

This project implements a smart ventilation system where a servo motor controls the opening of a vent based on temperature. A buzzer provides alert tones based on temperature levels.

This simulates real-world HVAC (heating, ventilation, and air conditioning) systems.

---

## Components Used

* DHT22 Sensor
* Servo Motor (SG90)
* Buzzer
* Arduino Uno

---

## Working Principle

* DHT22 reads temperature
* Temperature is mapped to servo angle
* Higher temperature → wider vent opening
* Buzzer gives alert tones based on severity

---

## System Logic

* Temp < 28°C → Vent Closed (0°), no alert
* 28–32°C → Half Open (90°), slow beep
* > 32°C → Fully Open (180°), fast beep

---

## Observations

* Smooth control of vent position
* Clear relation between temperature and angle
* Alert tones indicate severity

---

## Improvements

* Add manual override (button)
* Display temperature on LCD
* Add humidity-based control
* 
---

## Simulation link

https://wokwi.com/projects/460936536996237313

---

## Learning Outcomes

* Mapping sensor data to actuator position
* Servo control using PWM
* Multi-condition system design
* Intelligent feedback system

---

## Conclusion

This project demonstrates a smart ventilation system where environmental data directly controls mechanical movement and alert mechanisms.
