#include <Servo.h>

const int trigPin = 2; // Trigger pin of ultrasonic sensor
const int echoPin = 3; // Echo pin of ultrasonic sensor
const int servoPin = 9; // Control pin for servo motor

Servo myservo; // Servo object to control motor position

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;
  float level = map(distance, 10, 30, 0, 100);
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm | Level: ");
  Serial.print(level);
  Serial.println("%");
  
  if (level > 75) {
    myservo.write(0); // Open the lid
    delay(5000); // Wait for 5 seconds
    myservo.write(90); // Close the lid
  }
  
  delay(1000);
}
