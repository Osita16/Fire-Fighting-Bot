# 🔥 Fire Detection Robot

## 📌 Overview
This project is a **Fire Detection Robot** built using an Arduino Nano.  
It detects flames using a flame sensor and sprays water using a pump and a servo-controlled nozzle to help extinguish fire.

The project focuses on practical hardware implementation and reactive control logic, with scope for future improvements.

---

## 🤖 Robot Prototype
Below is the physical prototype of the fire detection robot used in this project.

<p align="center">
  <img src="https://github.com/user-attachments/assets/22502942-3be1-4e14-baee-8bdc9d501016" width="400"/>
</p>

*Physical prototype showing the Arduino Nano, flame sensor, water pump, relay module, DC motors, and servo-controlled nozzle.*

---

## ⚙️ Hardware Components
- Arduino Nano  
- Flame Sensor (IR-based)  
- DC Motors  
- Motor Driver (L298N / L293D)  
- Relay Module  
- Water Pump  
- Servo Motor (for nozzle rotation)  
- External Power Supply  
- Chassis and connecting wires  

---

## 🧠 Working Principle
1. The robot moves forward in patrol mode.  
2. When a flame is detected, the robot stops.  
3. The relay activates the water pump.  
4. The servo motor rotates the nozzle to spray water over a wider area.  
5. After spraying, the pump is turned off and the robot resumes operation.

---

## ✨ Features
- Flame detection using IR flame sensor  
- Relay-controlled water pump  
- Servo-based directional water spraying  
- Simple and reliable control logic  
- Real hardware-based implementation  

---

## 🛠️ Software Used
- Arduino IDE  
- Embedded C / Arduino programming  

---

## 📂 Project Structure
```Fire-Fighting-Bot/
├── code
  └── Flame_Detection.ino/
├── README.md
└── LICENSE
