# MCS-RDD
All the Activities done during the MCS 7-week  Robotics Development and Design Program
# Arduino Proximity Sensor Project

## Overview
This project involves an Arduino Uno, an ultrasonic sensor (HC-SR04), an I2C LCD display, a servo motor, and three LEDs. The system measures the distance of an object from the ultrasonic sensor, controls the servo motor based on the proximity, and uses LEDs to indicate the distance range.

## Components
- Arduino Uno
- Ultrasonic Sensor (HC-SR04)
- I2C LCD Display
- Servo Motor
- 3 LEDs
- Resistors (appropriate values for LEDs)
- Breadboard
- Jumper Wires

## Circuit Diagram
### Wiring:
1. **Ultrasonic Sensor (HC-SR04):**
   - VCC to 5V on the breadboard (shared with other components)
   - GND to GND on the breadboard (shared with other components)
   - Trig to Arduino pin 9
   - Echo to Arduino pin 10

2. **Servo Motor:**
   - VCC to 5V on the breadboard (shared with other components)
   - GND to GND on the breadboard (shared with other components)
   - Signal to Arduino pin 6

3. **LEDs (3 LEDs):**
   - Anode of each LED to Arduino pins 3, 4, and 5 through resistors
   - Cathode of each LED to GND on the breadboard (shared with other components)

4. **LCD Display with I2C:**
   - VCC to 5V on the breadboard (shared with other components)
   - GND to GND on the breadboard (shared with other components)
   - SDA to Arduino A4
   - SCL to Arduino A5
## Demo
## Watch The Video Below
[![Watch the video](https://img.youtube.com/vi/pjLezZWXZpc/hqdefault.jpg)](https://youtu.be/pjLezZWXZpc?si=BT92OjRr6tFw1MwS)

<div style="position: relative; width: max-content;">
  <a href="https://youtu.be/pjLezZWXZpc" target="_blank">
    <img src="https://img.youtube.com/vi/pjLezZWXZpc/hqdefault.jpg" alt="Watch the video" style="display: block;">
    <img src="https://img.icons8.com/?size=100&id=398&format=png&color=000000" alt="Play button" style="position: absolute; top: 50%; left: 50%; transform: translate(-50%, -50%);">
  </a>
</div>
