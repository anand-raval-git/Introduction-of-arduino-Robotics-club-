const int echoPin=7,tigPin=8;
#include<Servo.h>
Servo servo;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(tigPin,OUTPUT);
  pinMode(echoPin,INPUT);
 servo.attach(3);
}
void servoCall(int distance)
{
  if(distance<20)
  servo.write(0);
  // delay(1000);
  // servo.write(45);
  delay(1000);
  servo.write(90);
  // delay(1000);
  // servo.write(135);
  delay(1000);
  servo.write(180);
  delay(1000);
}
void loop() {
  // put your main code here, to run repeatedly
  long duration,distance;
  digitalWrite(tigPin,HIGH);
  delay(500);
  digitalWrite(tigPin,LOW);
  duration = pulseIn(echoPin,HIGH);
  distance = duration*0.034/2;
  Serial.print("Duration:");
  Serial.println(distance);
  servoCall(distance);
}
