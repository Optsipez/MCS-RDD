#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// Initialize LCD and Servo
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myServo;

// Pins
const int inputPin = 10;   // signal receiver pin ECHO to D4
const int outputPin = 9;  // signal transmitter pin TRIG to D5
const int servoPin = 6;
const int led1 = 3;
const int led2 = 4;
const int led3 = 5;

// Variables
int distance;
int servoPos = 0;

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);

  pinMode(inputPin, INPUT);
  pinMode(outputPin, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  myServo.attach(servoPin);
  myServo.write(0); // Initial position
}

void loop() {
  // Measure distance
  digitalWrite(outputPin, LOW);
  delayMicroseconds(2);
  digitalWrite(outputPin, HIGH);  // Pulse for 10μ s to trigger ultrasonic detection
  delayMicroseconds(10);
  digitalWrite(outputPin, LOW);
  distance = pulseIn(inputPin, HIGH);  // Read receiver pulse time
  distance = distance / 58;                // Transform pulse time to distance
  Serial.println(distance);
  
  // Clear the previous display and print the new distance
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Dist: ");
  lcd.print(distance);
  lcd.print(" cm");

  // LED Control Based on Distance
  if (distance < 25) { // Object is very close
    // Blink LEDs
    digitalWrite(led1, !digitalRead(led1));
    digitalWrite(led2, !digitalRead(led2));
    digitalWrite(led3, !digitalRead(led3));
    delay(500); // Adjust blink speed
  } else if (distance >= 25 && distance < 45) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  } else if (distance >= 45 && distance < 85) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
  } else if (distance >= 85 && distance < 100) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, HIGH);
  } else { // Distance is 100 or more
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }

  // Servo Control Based on Distance
  if (distance < 10) { // Object is very close
    if (servoPos < 180) {
      servoPos += 1;
      myServo.write(servoPos);
      delay(15);
    }
  } else { // Object is far
    if (servoPos > 0) {
      servoPos -= 1;
      myServo.write(servoPos);
      delay(15);
    }
  }

  // Print the servo position on the second row of the LCD
  lcd.setCursor(0, 1);
  lcd.print("Servo: ");
  lcd.print(servoPos);
  lcd.print(" deg");

  // Short delay to avoid excessive looping
  delay(100);
}
