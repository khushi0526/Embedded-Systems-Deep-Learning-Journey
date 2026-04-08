# Day 20 – IoT LED Control System (ESP32 + Web Interface)

## Overview

This project demonstrates how to control an LED using an ESP32 over WiFi. The system hosts a simple web server, allowing users to turn the LED ON or OFF from a browser.

This introduces Internet of Things (IoT) concepts and remote control systems.

---

## Components Used

* ESP32
* LED
* Resistor (220Ω)
* WiFi Network

---

## Simulation Link

https://wokwi.com/projects/460638257164223489

---

## Working Principle

* ESP32 connects to WiFi network
* It creates a web server
* User accesses IP address via browser
* Clicking buttons sends commands
* ESP32 controls LED accordingly

---

## System Logic

* Connect to WiFi
* Start web server
* Wait for user request
* ON request → LED ON
* OFF request → LED OFF

---

## Component Deep Dive

**ESP32**

* Microcontroller with built-in WiFi & Bluetooth
* More powerful than Arduino Uno
* Used for IoT applications

**Web Server**

* Runs on ESP32
* Handles HTTP requests
* Sends responses to browser

---

## Observations

* LED can be controlled remotely
* Response is almost instant
* Works within same WiFi network
* IP address required to access

---

## Challenges

* WiFi connection setup
* Understanding IP address
* Handling HTTP requests

---

## Improvements

* Add multiple device control
* Create mobile app interface
* Send sensor data to cloud

---

## Learning Outcomes

* Basics of IoT systems
* ESP32 programming
* Web-based control
* Network communication

---

## Conclusion

This project introduces IoT by enabling remote control of devices. It forms the foundation for smart home and connected systems.
