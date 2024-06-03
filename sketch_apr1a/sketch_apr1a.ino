#include <Wire.h>
#include <LIDARLite.h>
#include <Servo.h>

const int trigPin = 7; // trig pin of the ultrasonic sensor
const int echoPin = 6; // echo pin of the ultrasonic sensor
LIDARLite lidar; // create a LIDARLite object
Servo myservo; // create a servo object

void setup() {
  Serial.begin(9600); // initialize serial communication
  pinMode(trigPin, OUTPUT); // set the trig pin as an output
  pinMode(echoPin, INPUT); // set the echo pin as an input
  lidar.begin(0, true); // initialize the LIDARLite sensor with default I2C address
  myservo.attach(9); // attach the servo to pin 9
}

void loop() {
  // send a pulse to the trig pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // measure the duration of the echo pulse
  long duration = pulseIn(echoPin, HIGH);

  // calculate the distance in cm using the ultrasonic sensor
  int distance = duration * 0.034 / 2;

  // measure the distance in cm using the LIDARLite sensor
  int lidarDistance = lidar.distance();

  // print the distances to the serial monitor
  Serial.print("Ultrasonic Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  Serial.print("LIDAR Distance: ");
  Serial.print(lidarDistance);
  Serial.println(" cm");

  // move the servo based on the distance measured by the ultrasonic sensor
  if (distance < 30) {
    myservo.write(0); // turn the servo to 0 degrees
  } else if (distance >= 30 && distance < 60) {
    myservo.write(90); // turn the servo to 90 degrees
  } else {
    myservo.write(180); // turn the servo to 180 degrees
  }

  // delay for 500 milliseconds before taking another measurement
  delay(500);
}