# Day 16 – Automatic Door System (Ultrasonic + Servo)

## Overview

This project implements an automatic door system using an ultrasonic sensor and a servo motor. The system detects the distance of an object and opens the door when an object comes close.

This demonstrates real-world automation used in malls, offices, and smart entry systems.

---

## Components Used

* Ultrasonic Sensor (HC-SR04)
* Servo Motor (SG90)
* Arduino Uno
* Jumper Wires

---

## Simulation Link

https://wokwi.com/projects/460449096123750401

---

## Working Principle

* Ultrasonic sensor measures distance using sound waves
* Arduino calculates distance based on echo time
* If object is within threshold distance → servo rotates (door opens)
* If object moves away → servo returns (door closes)

---

## System Logic

* Distance < 20 cm → Door OPEN (servo 90°)
* Distance ≥ 20 cm → Door CLOSED (servo 0°)

---

## Component Deep Dive

**Ultrasonic Sensor**

* Uses time-of-flight principle
* Measures distance using echo
* Provides accurate distance measurement

**Servo Motor**

* Controls door position
* Rotates to specific angles
* Enables mechanical movement

---

## Observations

* Door opens smoothly when object is near
* Distance threshold affects behavior
* Slight delay due to sensor reading
* System reacts in real-time

---

## Challenges

* Correct distance calculation
* Synchronizing sensor and servo
* Avoiding jitter in servo movement

---

## Improvements

* Add delay so door stays open longer
* Use PIR instead of ultrasonic
* Add buzzer for indication

---

## Learning Outcomes

* Interfacing sensor with actuator
* Building mechanical automation system
* Understanding distance-based control
* Real-world embedded system design

---

## Conclusion

This project demonstrates a practical automation system where sensing and actuation are combined. It is widely used in real-world smart entry systems.
