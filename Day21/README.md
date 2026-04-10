# Day 22 – Smart Temperature Alert System (DHT11 + LED + Buzzer)

## Overview

This project implements a temperature-based alert system using a DHT11 sensor. The system monitors environmental conditions and provides alerts using LED and buzzer when the temperature exceeds a defined threshold.

This simulates real-world safety systems used in industrial and home automation.

---

## Components Used

* DHT11 Sensor
* LED
* Buzzer
* Arduino Uno

---

## Simulation Link

https://wokwi.com/projects/460926296014131201

---

## Working Principle

* DHT11 reads temperature
* Arduino checks threshold condition
* If temperature exceeds limit:

  * LED turns ON
  * Buzzer activates
* Otherwise:

  * System remains OFF

---

## System Logic

* Temp < 30°C → Normal
* Temp ≥ 30°C → Alert ON

---

## Observations

* Immediate alert on threshold crossing
* Buzzer provides real-time warning
* LED gives visual indication

---

## Improvements

* Add multiple thresholds (low/medium/high)
* Display values on LCD
* Add fan control

---

## Learning Outcomes

* Condition-based control
* Sensor + actuator integration
* Alert system design
* Real-world embedded logic

---

## Conclusion

This project demonstrates a basic yet powerful alert system used in monitoring and safety applications.
