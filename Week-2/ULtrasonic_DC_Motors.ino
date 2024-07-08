// Define pins for encoder motor and ultrasonic sensor
#define motorA 5  // Encoder motor pin A
#define motorB 6  // Encoder motor pin B
#define echoPin 10 // Ultrasonic sensor echo pin
#define trigPin 11 // Ultrasonic sensor trig pin

// Define pins for ordinary DC motor
int OLDCp = 8;  // Ordinary DC motor positive pin
int OLDCm = 9;  // Ordinary DC motor negative pin

void setup() {
  // Set motor pins as outputs
  pinMode(motorA, OUTPUT);
  pinMode(motorB, OUTPUT);
  pinMode(OLDCp, OUTPUT);
  pinMode(OLDCm, OUTPUT);
  
  // Set ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  long duration, distance;
  
  // Send a pulse from the trig pin to initiate distance measurement
  digitalWrite(trigPin, LOW);  // Set trig pin low for 2 microseconds
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); // Set trig pin high for 10 microseconds
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);  // Set trig pin low again
  
  // Read the pulse on the echo pin and calculate distance
  duration = pulseIn(echoPin, HIGH); // Measure the duration of the pulse
  distance = duration / 58; // Convert duration to distance in cm
  
  // Print the measured distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  
  if (distance < 20) {
    // If distance is less than 20 cm, run encoder motor back and forth
    
    // Encoder motor clockwise
    analogWrite(motorB, 255); // Set motorB speed to maximum
    digitalWrite(motorA, LOW); // Set motorA to low
    delay(700); // Wait for 700 milliseconds
    
    // Encoder motor counterclockwise
    analogWrite(motorA, 255); // Set motorA speed to maximum
    digitalWrite(motorB, LOW); // Set motorB to low
    delay(700); // Wait for 700 milliseconds
    
  } else if (distance < 50) {
    // If distance is between 20 cm and 50 cm, run ordinary DC motor back and forth
    
    // OLDC motor clockwise
    digitalWrite(OLDCp, HIGH); // Set OLDCp to high
    digitalWrite(OLDCm, LOW); // Set OLDCm to low
    delay(700); // Wait for 700 milliseconds
    
    // OLDC motor counterclockwise
    digitalWrite(OLDCp, LOW); // Set OLDCp to low
    digitalWrite(OLDCm, HIGH); // Set OLDCm to high
    delay(700); // Wait for 700 milliseconds
    
  } else {
    // If distance is greater than 50 cm, stop all motors
    
    digitalWrite(motorA, LOW); // Set motorA to low
    digitalWrite(motorB, LOW); // Set motorB to low
    digitalWrite(OLDCp, LOW); // Set OLDCp to low
    digitalWrite(OLDCm, LOW); // Set OLDCm to low
  }
  
  delay(1000); // Wait for 1 second before the next measurement
}
