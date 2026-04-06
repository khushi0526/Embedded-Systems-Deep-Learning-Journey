# Day 19 – Temperature & Humidity Monitoring System (DHT22)

## Overview

This project demonstrates how to measure temperature and humidity using the DHT22 sensor. The system reads environmental data and displays it via Serial Monitor.

This is widely used in IoT, weather monitoring, and smart home systems.

---

## Components Used

* DHT22 Sensor
* Arduino Uno
* Jumper Wires

---

## Simulation Link

https://wokwi.com/projects/460541667635997697

---

## Working Principle

* DHT22 measures temperature and humidity
* It sends digital data to Arduino
* Arduino processes and displays values

Unlike analog sensors, DHT22 uses a **single-wire digital communication protocol**.

---

## System Logic

* Read temperature
* Read humidity
* Display values
* Repeat continuously

---

## Component Deep Dive

**DHT22 Sensor**

* Measures temperature (°C) and humidity (%)
* Uses digital communication
* Slower compared to other sensors (~1 sec delay)
* Limited accuracy but easy to use

---

## Observations

* Readings update every ~1 second
* Values change based on environment
* Slight delay in response
* Stable output compared to analog sensors

---

## Challenges

* Library installation
* Handling read errors
* Understanding digital protocol

---

## Improvements

* Display on LCD/OLED
* Add alert system (buzzer for high temp)
* Use DHT22 for better accuracy

---

## Learning Outcomes

* Working with digital sensors
* Reading environmental data
* Using external libraries
* Understanding sensor limitations

---

## Conclusion

This project introduces environmental sensing using DHT22. It forms the foundation for IoT-based monitoring systems.
