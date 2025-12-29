# Smart Obstacle-Avoiding & Firefighting Robot

## Overview
This project integrates autonomous navigation with safety features to create a smart robotic car. It is capable of moving through an environment while avoiding obstacles and automatically detecting and extinguishing fires using a water pump system.

## Features
* **Autonomous Navigation:** Moves forward automatically and detects obstacles using an ultrasonic sensor.
* **Smart Obstacle Avoidance:** Stops upon detecting an object, scans left and right, and turns toward the clearer path.
* **Fire Detection:** Continuously monitors air quality for smoke using an MQ-2 sensor.
* **Automatic Extinguishing:** Automatically activates a water pump when smoke levels exceed a safety threshold.

## Hardware Used
* **Microcontroller:** Arduino Uno
* **Sensors:**
    * Ultrasonic Sensor (HC-SR04) for distance measurement
    * MQ-2 Smoke Sensor for fire detection
* **Actuators:**
    * Servo Motor (SG90) for scanning
    * 2x DC Motors for movement
    * Submersible Water Pump
* **Drivers & Power:**
    * L293D Motor Driver
    * Relay Module (to switch the pump)
    * Power Supply (Battery)

## Pin Configuration
Use this mapping to connect your components to the Arduino Uno:

* **Left Motor:** Pins 2 & 3 (Enable Pin: 6)
* **Right Motor:** Pins 4 & 5 (Enable Pin: 7)
* **Ultrasonic Sensor (Trig):** Pin 9
* **Ultrasonic Sensor (Echo):** Pin 10
* **Servo Motor:** Pin 8
* **Relay Module (Water Pump):** Pin 11
* **Smoke Sensor:** Pin A0

## Software & Dependencies
* **Language:** Arduino C++
* **IDE:** Arduino IDE
* **Libraries:** `Servo.h` (Built-in Arduino library)

## Setup Instructions
1.  **Assembly:** Connect all hardware components according to the **Pin Configuration** above and the circuit diagram.
2.  **Software:** Open the `src/main.ino` file in the Arduino IDE.
3.  **Library Check:** Ensure the standard `Servo` library is available.
4.  **Upload:** Connect the Arduino Uno to your PC and upload the code.
5.  **Power Up:** Connect the battery power supply. The car should immediately start moving and sensing.

## Working Principle

### 1. Obstacle Avoidance
The car continuously measures distance. If an object is detected within **20 cm**:
1.  The car stops.
2.  The servo looks left (0°) and right (180°) to measure distances.
3.  The car turns toward the direction with more space and resumes moving forward.

### 2. Firefighting
The MQ-2 sensor reads analog smoke values. If the value exceeds the threshold of **300**:
1.  The relay activates (High signal).
2.  The water pump turns on to extinguish the fire.
3.  When smoke levels drop below the threshold, the pump turns off automatically.

## Circuit Diagram
![Circuit Diagram](images/circuit.jpg)

## Results
* **Prototype Photos:** View the project photos in the `/images` directory.
* **Demo Videos:** Watch the car in action in the `/media` directory.

## Future Scope
* **IoT Integration:** Add a Wi-Fi module (ESP8266/ESP32) for remote monitoring and alerts.
* **Sensor Fusion:** Add infrared sensors for better edge detection.
* **App Control:** Enable manual override via a smartphone app.
