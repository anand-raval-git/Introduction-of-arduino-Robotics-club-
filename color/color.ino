#include<Servo.h>
Servo myservo;


void setup() {
  // put your setup code here, to run once:
  myservo.attach(2);
 
  pinMode(8,OUTPUT);//s0
  pinMode(9,OUTPUT);//s1
  pinMode(10,OUTPUT);//s2
  pinMode(11,OUTPUT);//s3
  pinMode(11,INPUT);//out
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);

  frequency = pulseIn(sensorOut, LOW);

  int R = frequency;

  Serial.print("Red = ");

  Serial.print(frequency);//printing RED color frequency

  Serial.print("   ");

  delay(50);

  

 digitalWrite(S2, LOW);

  digitalWrite(S3, HIGH);

  frequency = pulseIn(sensorOut, LOW);

  int B = frequency;

  Serial.print("Blue = ");

  Serial.print(frequency);

  Serial.println("   ");

  

  // activating green photodiodes to read

  digitalWrite(S2, HIGH);

  digitalWrite(S3, HIGH);

  // Reading the output frequency

  frequency = pulseIn(sensorOut, LOW);

  int G = frequency;

  Serial.print("Green = ");

  Serial.print(frequency);

  Serial.print("   ");

  delay(50);


  delay(50);  

}
