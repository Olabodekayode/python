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
  
//   Another program
  This program is for the use of ultrasonic sensor and servo 
  
#include <Servo.h>
int TrigPin = 13;
int EchoPin = 11;
int ServoPin = 9;
int redLed = 3;
float servoAngle;

float targetDistance;
float pingTime;
float SpeedOfSound = 776.7;
Servo Mypointer;

void setup ()
{
  Serial.begin (9600);
  pinMode (TrigPin, OUTPUT);
  pinMode (EchoPin, INPUT);
  pinMode (ServoPin, OUTPUT);

  Mypointer.attach (ServoPin);

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

  Serial.print ("Distance of the object ");
  Serial.print (targetDistance);
  Serial.println (" inches");

  if (targetDistance > 4.0)
  {
    analogWrite (redLed, targetDistance );

  }
  else
    analogWrite (redLed, LOW);


  servoAngle = 106. / 7. * (targetDistance) + 37;
  Mypointer.write(servoAngle);
}
  

  LCD.setCursor(0, 1);
  LCD.print ("                 ");
  LCD.setCursor(0, 1);
  LCD.print (targetDistance);
  LCD.print ("inches");
  delay (250);

}
