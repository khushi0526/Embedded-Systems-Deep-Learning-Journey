# Day 18 – Buzzer Sound System (Alert & Tone Generation)

## Overview

This project demonstrates how to use a buzzer to generate sound signals. The system produces different tones and can be used as an alert mechanism in embedded systems.

Buzzers are commonly used in alarms, notifications, and feedback systems.

---

## Components Used

* Buzzer (Active or Passive)
* Arduino Uno
* Jumper Wires

---

## Simulation Link

https://wokwi.com/projects/460538451583427585

---

## Working Principle

There are two types of buzzers:

* **Active Buzzer** → Produces sound when powered (simple ON/OFF)
* **Passive Buzzer** → Requires frequency signal (tone generation)

Arduino can generate tones using PWM signals.

---

## System Logic

* Generate tone at specific frequency
* Pause
* Generate another tone
* Repeat

---

## Component Deep Dive

**Buzzer**

* Converts electrical signal into sound
* Used for alerts and feedback
* Can produce different frequencies (passive type)

---

## Observations

* Different frequencies produce different sounds
* Active buzzer gives simple beep
* Passive buzzer allows melody generation
* Sound intensity depends on power

---

## Challenges

* Identifying buzzer type
* Choosing correct frequency
* Controlling sound duration

---

## Improvements

* Create melody (songs)
* Combine with sensors (alert system)
* Add different patterns for different events

---

## Learning Outcomes

* Understanding sound generation in embedded systems
* Using PWM for tone control
* Creating alert mechanisms
* Expanding system feedback methods

---

## Conclusion

This project introduces sound-based output, allowing embedded systems to communicate with users through audio signals.
