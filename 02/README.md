# Day 2 – Ultrasonic Sensor Based Obstacle Detection System

## Overview

This project demonstrates an obstacle detection system using an ultrasonic sensor and a buzzer. The system measures the distance of nearby objects and provides an alert when an object comes within a defined range.

The implementation is simulated using Wokwi, an online platform for testing embedded systems.

---

## Simulation Link

https://wokwi.com/projects/459384990102688769

---

## Components Used

* Ultrasonic Sensor (HC-SR04)
* Buzzer
* Arduino Uno
* Jumper Wires

---

## Working Principle

The ultrasonic sensor works on the **time-of-flight principle**:

1. A trigger signal is sent to the sensor
2. The sensor emits ultrasonic waves
3. Waves reflect back after hitting an object
4. The echo signal is received
5. The time taken is used to calculate distance

This allows continuous monitoring of object distance.

---

## System Logic

* If the object is far → no alert is generated
* If the object comes within a threshold distance → buzzer is activated
* The system continuously updates based on real-time distance

---

## Observations

* Distance values change dynamically with object movement
* Sensor accuracy depends on object surface and angle
* Minor fluctuations are present in readings
* System response depends on timing and delay

---

## Challenges

* Understanding trigger and echo timing
* Handling fluctuating sensor values
* Choosing an appropriate threshold distance

---

## Improvements

* Implement distance-based buzzer variation
* Add visual indicators (LED/OLED)
* Apply filtering for stable readings

---

## Learning Outcomes

* Understanding ultrasonic distance measurement
* Importance of timing in embedded systems
* Interfacing sensors with actuators
* Converting real-world signals into meaningful output

---

## Conclusion

This project demonstrates a basic sensing and response system, which is fundamental in embedded applications such as obstacle detection and assistive systems.
