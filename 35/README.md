# Day 35 – Bluetooth-Based Control System (Simulated in SimulIDE)

## 📌 Overview

This project demonstrates a Bluetooth-based control system using Arduino. Since physical hardware was not available, the system was implemented and tested in SimulIDE by simulating Bluetooth communication through a serial terminal.

---

## 🧰 Components Used

* Arduino Uno (Simulated)
* LED
* Servo Motor
* Virtual Terminal (used as Bluetooth interface)

---

## ⚙️ Simulation Approach

In place of a physical HC-05 Bluetooth module, a virtual terminal in SimulIDE was used to emulate serial communication.

* User inputs commands via terminal
* Arduino reads serial data
* Corresponding actions are executed

This approach replicates real-world Bluetooth communication logic.

---

## 🔄 System Working

1. User sends command from terminal
2. Serial data is received by Arduino
3. Arduino processes input
4. LED or Servo responds accordingly

---

## 🎮 Commands

| Command | Action        |
| ------- | ------------- |
| `1`     | LED ON        |
| `0`     | LED OFF       |
| `S`     | Servo to 0°   |
| `M`     | Servo to 90°  |
| `F`     | Servo to 180° |

---

## 🧠 Learning Outcomes

* Understanding serial communication
* Simulation of wireless control systems
* Command-based device control
* Practical approach to embedded system testing without hardware

---

## ✅ Conclusion

This project successfully demonstrates a Bluetooth-controlled system using simulation tools. It highlights how embedded system logic can be developed and tested without physical components, making it a strong foundation for future IoT applications.

---
