const int ENA = 10; // PWM pin for motor 1
const int IN1 = 9;  // Digital pin for motor 1
const int IN2 = 8;  // Digital pin for motor 1
const int ENB = 5;  // PWM pin for motor 2
const int IN3 = 7;  // Digital pin for motor 2
const int IN4 = 6;  // Digital pin for motor 2

// Set the motor speed (0-255)
int motorSpeed = 150;

void setup() {
  // Set the motor driver pins as outputs
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  // Set motor 1 direction and speed
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, motorSpeed);
  
  // Set motor 2 direction and speed
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, motorSpeed);
  
  // Wait for 2 seconds
  delay(2000);
  
  // Stop motors
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
  
  // Wait for 2 seconds
  delay(2000);
  
  // Set motor 1 direction and speed
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, motorSpeed);
  
  // Set motor 2 direction and speed
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, motorSpeed);
  
  // Wait for 2 seconds
  delay(2000);
  
  // Stop motors
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
  
  // Wait for 2 seconds
  delay(2000);
}