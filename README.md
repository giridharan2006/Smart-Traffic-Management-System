# Smart Traffic Management System 🚦

## Overview
This project is a prototype of an adaptive Smart Traffic Management System built using an ESP32 and Computer Vision.

Two USB webcams monitor two traffic lanes in real time. Python and OpenCV process the video streams to estimate the number of vehicles in each lane. The vehicle counts are sent to an ESP32 over serial communication, which controls the traffic lights based on traffic density.

The goal is to reduce unnecessary waiting time by dynamically adjusting traffic signal durations.

---

## Features

- Real-time vehicle monitoring using two webcams
- Vehicle counting using OpenCV
- Adaptive traffic signal timing
- ESP32-based traffic light control
- Serial communication between Python and ESP32
- Fair signal allocation with additional green time when traffic remains heavy

---

## Hardware Used

- ESP32 Dev Board
- 2 USB Webcams
- 4 LEDs (2 Red, 2 Green)
- 4 × 330Ω Resistors
- Breadboard
- Jumper Wires
- USB Cable

---

## Software Used

- Arduino IDE
- Python 3
- OpenCV
- PySerial
- NumPy

---

## Project Structure

```
SmartTrafficSystem/
│
├── smart_traffic_system_esp32.ino
├── traffic_cam.py
├── README.md
```

---

## Working Principle

1. Two webcams capture live traffic from two lanes.
2. Python processes each video stream using OpenCV.
3. The vehicle count of each lane is sent to the ESP32 through serial communication.
4. ESP32 compares the traffic density.
5. The lane with higher traffic receives a green signal for 60 seconds.
6. If the same lane continues to have significantly higher traffic, it receives an additional 20-second buffer before switching.
7. The other lane is then given its turn to avoid excessive waiting.

---

## How to Run

### ESP32

1. Open `smart_traffic_system_esp32.ino`
2. Select the correct ESP32 board.
3. Select the correct COM port.
4. Upload the code.

### Python

Install required packages:

```bash
pip install opencv-python pyserial numpy
```

Run:

```bash
python traffic_cam.py
```

---

## Future Improvements

- YOLO-based vehicle detection
- Emergency vehicle priority
- Multi-lane traffic support
- Traffic statistics dashboard
- Cloud-based monitoring
- Automatic incident detection

---

## Technologies

- ESP32
- Arduino IDE
- Python
- OpenCV
- Serial Communication
- Computer Vision

---

## Author

**Giridharan S**

VIT Vellore

