# Day 7 – Sensor Calibration and Stable Output (LDR + Filtering)

## Overview

This project focuses on improving the reliability of sensor readings by applying calibration and filtering techniques. Instead of directly using raw LDR values, the system smooths the input and makes more stable decisions.

This helps reduce noise and improves real-world performance.

---

## Components Used

* LDR (Light Dependent Resistor)
* LED
* Arduino Uno
* Resistor (10kΩ)

---

## Simulation Link

https://wokwi.com/projects/459939454365861889

---

## Working Principle

LDR values fluctuate due to:

* Ambient light variations
* Electrical noise
* Sensor sensitivity

To handle this:

* Multiple readings are taken
* Average value is calculated
* Decision is made using stable data

---

## System Logic

* Read LDR value multiple times
* Calculate average
* Compare with threshold
* Control LED based on stable value

---

## Component Deep Dive

**LDR**

* Analog sensor with continuous variation
* Highly sensitive to environmental changes
* Needs filtering for stable output

**Filtering Concept**

* Uses averaging to reduce noise
* Improves reliability of sensor readings
* Common technique in embedded systems

---

## Observations

* Raw values fluctuate frequently
* Averaging makes output smoother
* LED behavior becomes more stable
* System feels more reliable

---

## Challenges

* Choosing number of samples for averaging
* Balancing responsiveness vs stability
* Setting correct threshold after filtering

---

## Improvements

* Use moving average instead of simple average
* Implement adaptive threshold
* Combine with previous projects (LDR + PIR + filtering)

---

## Learning Outcomes

* Importance of sensor calibration
* Handling noisy real-world signals
* Improving system stability
* Difference between raw and processed data

---

## Conclusion

This project highlights the importance of signal conditioning in embedded systems. By applying filtering techniques, the system becomes more stable and reliable for real-world applications.
