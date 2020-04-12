#include <LiquidCrystal.h>
LiquidCrystal LCD (10, 9, 5, 4, 3, 2);
int TrigPin = 13;
int EchoPin = 11;
float targetDistance;
float pingTime;
float SpeedOfSound = 776.5;

void setup ()
{
  Serial.begin (9600);
  pinMode (TrigPin, OUTPUT);
  pinMode (EchoPin, INPUT);
  
  LCD.begin (16, 2);
  LCD.setCursor (0, 0);
  LCD.print ("Target Distance:  ");

}

void loop ()
{
  digitalWrite (TrigPin, LOW);
  delayMicroseconds (2000);
  digitalWrite (TrigPin, HIGH);
  delayMicroseconds (15);
  digitalWrite (TrigPin, LOW);

  pingTime = pulseIn(EchoPin, HIGH);
  pingTime = pingTime / 1000000;
  pingTime = pingTime / 3600;

  targetDistance = SpeedOfSound * pingTime;
  targetDistance = targetDistance / 2;
  targetDistance = targetDistance * 63360;

  Serial.print ("Target Distance: ");
  Serial.print (targetDistance);
  Serial.println (" m");

  LCD.setCursor(0, 1);
  LCD.print ("                 ");
  LCD.setCursor(0, 1);
  LCD.print (targetDistance);
  LCD.print ("inches");
  delay (250);

}
