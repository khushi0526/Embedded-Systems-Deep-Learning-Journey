# Day 24 – Smart Room Automation System

## Overview

This project integrates multiple sensors and actuators to simulate a smart room system. It controls lighting, ventilation, and alerts based on environmental conditions.

---

## Components Used

* LDR (Light Sensor)
* DHT11 (Temperature Sensor)
* Servo Motor
* LED
* Buzzer
* Arduino Uno

---

## Working Principle

* LDR detects light intensity → controls LED
* DHT11 reads temperature → controls servo (vent)
* High temperature → triggers buzzer alert

---

## Simulation Link

https://wokwi.com/projects/461015038709844993

---

## System Logic

### Light Control:

* Dark → LED ON
* Bright → LED OFF

### Vent Control:

* Temp < 28°C → Closed (0°)
* 28–32°C → Half Open (90°)
* > 32°C → Fully Open (180°)

### Alert:

* Temp > 32°C → Fast buzzer alert

---

## Learning Outcomes

* Multi-sensor integration
* Parallel system design
* Real-world automation logic
* System-level thinking

---

## Conclusion

This project simulates a smart room where multiple environmental parameters are monitored and controlled automatically.
