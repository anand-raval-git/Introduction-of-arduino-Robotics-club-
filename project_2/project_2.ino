#include <LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);

#define outPin 8
#define s0 9
#define s1 10 
#define s2 11
#define s3 12

boolean DEBUG = true;


int  red , grn , blu;
String color ="";
long startTiming = 0;
long elapsedTime = 0;

void setup()
{
  Serial.begin(9600);
  
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(outPin, INPUT);

  digitalWrite(s0,HIGH);
  digitalWrite(s1,HIGH);

  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("Welcome To");
  lcd.setCursor(1,1);
  lcd.print("color Detector");
  delay(2000); 
  lcd.clear();
  startTiming = millis();
  }

void loop()
{
  gettColor();

  if(DEBUG)PrintData();
  elapsedTime = millis()-startTiming;
  if(elapsedTime > 1000)
  {
showDataLCD();
startTiming=millis();
  }
}

void readRGB()
{
  red = 0 , grn=0 , blu=0;

  int n=10;
  for(int i=0;i<n;++i)
  {
    digitalWrite(s2,LOW);
    digitalWrite(s3,LOW);
    red = red + pulseIn(outPin,LOW);

    digitalWrite(s2,HIGH);
    digitalWrite(s3,HIGH);
    grn = grn + pulseIn(outPin,LOW);

    digitalWrite(s2,LOW);
    digitalWrite(s3,HIGH);
    blu = blu + pulseIn(outPin,LOW);    
  }
  red = red/n;
  grn =  grn/n;
  blu = blu/n; 
  }

  void PrintData(void)
  {
    Serial.print("red=");
    Serial.print(red);
    Serial.print("red=");
    Serial.print("green=");
    Serial.print(grn);
    Serial.print("blue=");
    Serial.print(blu);
    Serial.print(" - ");
    Serial.print(color);
    Serial.println("detected!");
  }

  void showDataLCD(void)
  {
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("R");
   lcd.print(red);
   lcd.setCursor(6,0);
   lcd.print("G");
   lcd.print(grn);
   lcd.setCursor(12,0);
   lcd.print("B");
   lcd.print(blu);
   lcd.setCursor(0,1);
   lcd.print("Color:");
   lcd.print(color);      
  }

  void gettColor()
  {
readRGB();

  if(red>7 && red<30 && grn>17 && grn<25 && blu>13 && blu<40) color ="RED";
 else if(red>17 && red<21 && grn>11 && grn<40 && blu>30 && blu<40) color ="GREEN";
 else if(red>15 && red<50 && grn>25 && grn<40 && blu>30 && blu<40) color ="BLUE";
 else if(red>4 && red<8 && grn>6 && grn<10 && blu>9 && blu<13) color ="YELLOW";
 else if(red>5 && red<8 && grn>4 && grn<8 && blu>3 && blu<7) color ="WHITE";
 else color = "NO_COLOR";
}