📝 Day 1: LDR-Based Light Control (Basic → Advanced)
🔹 Project Overview

This project demonstrates how an LDR (Light Dependent Resistor) can be used to control an LED based on ambient light.

Two implementations are explored:

Basic Version → LED ON/OFF using threshold
Advanced Version → LED brightness varies smoothly using PWM

Simulation is done using Wokwi, which allows testing embedded systems without physical hardware.

🔗 Simulation Links
🔹 Basic ON/OFF System:
https://wokwi.com/projects/459366528384393217
🔹 Variable Brightness System:
https://wokwi.com/projects/459367279875913729
🔹 Components Used
LDR (Photoresistor)
Resistor (220Ω)
LED
Arduino Uno
Breadboard & Jumper Wires
🔹 Working Principle

The LDR works based on photoconductivity:

More light → lower resistance
Less light → higher resistance

A voltage divider circuit is used to convert resistance changes into voltage, which is read using an analog pin. The output voltage varies with illumination.

🔹 Version 1: Basic ON/OFF Control
📌 Logic
If light is low → LED ON
If light is high → LED OFF
🧠 Concept Used
Analog reading
Threshold comparison
⚠️ Limitation
Sudden switching (not smooth)
No gradual control
🔹 Version 2: Variable Brightness Control
📌 Logic
LED brightness changes gradually based on light intensity
🧠 Concept Used
PWM (Pulse Width Modulation)
Mapping analog values to brightness
Low light → High brightness
High light → Low brightness

This creates a more realistic and efficient control system.

🔹 Key Learning Difference
Feature	Basic Version	Advanced Version
Output	ON/OFF	Smooth brightness
Logic	Threshold	Continuous control
Complexity	Low	Medium
Real-world usage	Limited	Practical
🔹 Code Insight
analogRead() → reads light level (0–1023)
map() → converts sensor value to PWM range (0–255)
analogWrite() → controls LED brightness

PWM allows gradual brightness control instead of binary switching.

🔹 Challenges Faced
Fluctuating LDR readings
Difficulty in selecting threshold
Understanding PWM mapping
🔹 Improvements
Add smoothing (averaging readings)
Auto-calibration of threshold
Use filtering techniques to reduce noise
🔹 What I Learned
Difference between digital and analog control
How voltage divider circuits work
How to convert real-world signals into controllable outputs
Importance of gradual control in embedded systems

🚀 Conclusion
This project shows the transition from basic logic-based control to real-world analog behavior, which is fundamental in embedded systems design.
