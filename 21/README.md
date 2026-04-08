# Day 21 – IoT Temperature & Humidity Monitoring (ESP32 + Web Server)

## Overview

This project extends IoT functionality by displaying real-time temperature and humidity data on a web page using ESP32 and DHT22.

The system acts as a mini web server that continuously updates environmental data, accessible through a browser.

---

## Components Used

* ESP32
* DHT22 Sensor
* WiFi Network

---

## Simulation Link

https://wokwi.com/projects/460756602703670273

---

## Working Principle

* ESP32 connects to WiFi
* Reads data from DHT22 sensor
* Hosts a web server
* Displays temperature and humidity on a web page
* User accesses data via browser

---

## System Logic

* Connect to WiFi
* Read sensor data
* Wait for client request
* Send updated values to web page

---

## Component Deep Dive

**ESP32**

* Handles WiFi + processing
* Runs web server

**DHT11**

* Provides temperature and humidity
* Sends digital data

**Web Interface**

* Displays real-time data
* Refreshes periodically

---

## Observations

* Data updates in real time
* Accessible from any device in network
* Slight delay due to sensor reading
* Simple UI but effective

---

## Challenges

* Combining WiFi + sensor
* Formatting HTML response
* Handling sensor read failures

---

## Improvements

* Auto-refresh page
* Add graphs (Thingspeak)
* Control devices along with monitoring

---

## Learning Outcomes

* IoT data monitoring
* Integrating sensors with web systems
* Real-time data display
* Building full IoT pipeline

---

## Conclusion

This project demonstrates a complete IoT monitoring system. It forms the foundation for smart environments, weather stations, and industrial monitoring systems.
