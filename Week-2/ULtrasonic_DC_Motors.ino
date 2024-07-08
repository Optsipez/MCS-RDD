// Two pin definition techniques
#define motorA 5
#define motorB 6
#define echoPin 10
#define trigPin 11

int OLDCp = 8;
int OLDCm = 9;

void setup() {
  pinMode(motorA, OUTPUT);
  pinMode(motorB, OUTPUT);
  pinMode(OLDCp, OUTPUT);
  pinMode(OLDCm, OUTPUT);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  Serial.begin(9600); // Initialize serial communication for debugging
}

void loop() {
  long duration, distance;
  
  // Send a pulse from the trig pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the pulse on the echo pin
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58; 
  
  Serial.print("Distance: ");
  Serial.println(distance);
  
  if (distance < 20) {
    // Encoder motor clockwise
    analogWrite(motorB, 255);
    digitalWrite(motorA, LOW);
    delay(700);
    
    // Encoder motor counterclockwise
    analogWrite(motorA, 255);
    digitalWrite(motorB, LOW);
    delay(700);
  } else if (distance < 50) {
    // OLDC motor clockwise
    digitalWrite(OLDCp, HIGH);
    digitalWrite(OLDCm, LOW);
    delay(700);
    
    // OLDC motor counterclockwise
    digitalWrite(OLDCp, LOW);
    digitalWrite(OLDCm, HIGH);
    delay(700);
  } else {
    // Stop all motors
    digitalWrite(motorA, LOW);
    digitalWrite(motorB, LOW);
    digitalWrite(OLDCp, LOW);
    digitalWrite(OLDCm, LOW);
  }
  
  delay(1000); // Delay to avoid continuous triggering
}
