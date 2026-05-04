# 🔵 ESP32 IR Remote Bluetooth Keyboard

Control your PC using a normal IR remote via ESP32 Bluetooth.

---

## 🚀 Features
- Open Chrome & YouTube
- Media control (Play/Pause, Next, Previous)
- Volume control
- Window control (Minimize/Maximize)
- Shutdown PC
- Task Manager shortcut

---

## 🧰 Hardware Required
- ESP32 Dev Board  
- IR Receiver (TSOP1838 or similar)  
- IR Remote (TV/AC remote)  
- Jumper wires  

---

## 🔌 Wiring

| IR Receiver Pin | ESP32 Pin |
|----------------|----------|
| VCC            | 3.3V     |
| GND            | GND      |
| OUT            | GPIO 15  |

---

## 📚 Libraries Required
Install in Arduino IDE:

- IRremote
- ESP32 BLE Keyboard

---

## ⚙️ Arduino IDE Setup
- Board: ESP32 Dev Module  
- ESP32 Version: 2.0.14 (recommended for stability)  
- Upload speed: 115200  

---

## 🎮 Remote Button Functions

| Button | Action |
|--------|--------|
| Power | Shutdown menu |
| 1 | Open Chrome |
| 2 | Open YouTube |
| 3 | Play / Pause |
| 4 | Previous track |
| 5 | Next track |
| 6 | Mute |
| 7 | Minimize window |
| 8 | Maximize window |
| 9 | Close tab |
| 0 | Close app |
| Vol+ | Volume up |
| Vol- | Volume down |
| Mode | Task Manager |
| Mute | Mute/Unmute |
| ◀ | Left arrow |
| ▶ | Right arrow |

---

## 📲 How to Use
1. Upload code to ESP32  
2. Turn on Bluetooth on PC  
3. Pair device: **IR Remote PC**  
4. Use remote to control PC 🎉  

---

## 🧠 How It Works
- IR remote sends signal  
- ESP32 reads IR code  
- Converts it into keyboard input  
- Sends via Bluetooth to PC  

---

## ⭐ Project Info
- Author: Your Name  
- Platform: ESP32 + Arduino IDE  
- Type: IoT + Automation Project  

---

## ⭐ If you like this project
Give it a star on GitHub ⭐
