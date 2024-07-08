# MCS-RDD
All the Activities done during the MCS 7-week  Robotics Development and Design Program

# Branch Links
- <a href="https://github.com/Optsipez/MCS-RDD.git" style="color: white; text-decoration: none; font-weight: bold; background-color: #0366d6; padding: 10px 15px; border-radius: 5px; box-shadow: 2px 2px 5px rgba(0,0,0,0.3);" onmouseover="this.style.backgroundColor='#ff6347'" onmouseout="this.style.backgroundColor='#0366d6'"><img src="RDD.jpeg" alt="Week - 1" title="Week - 1" style="width: 20px; border: 2px solid #000; border-radius: 10px; box-shadow: 5px 5px 15px rgba(0,0,0,0.3);"/>Week - 1 </a>

- <a href="https://github.com/Optsipez/MCS-RDD/tree/Week-2" style="color: white; text-decoration: none; font-weight: bold; background-color: #0366d6; padding: 10px 15px; border-radius: 5px; box-shadow: 2px 2px 5px rgba(0,0,0,0.3);" onmouseover="this.style.backgroundColor='#ff6347'" onmouseout="this.style.backgroundColor='#0366d6'"><img src="RDD.jpeg" alt="Week - 2" title="Week - 2" style="width: 20px; border: 2px solid #000; border-radius: 10px; box-shadow: 5px 5px 15px rgba(0,0,0,0.3);"/>Week - 2 </a>
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

