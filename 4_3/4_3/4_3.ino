#include <Ultrasonic.h>
#define red 2
#define green 3
#define blue 4
Ultrasonic ultrasonic(6);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
 ultrasonic.MeasureInCentimeters();
 int x = ultrasonic.RangeInCentimeters;
 delay(100);
  Serial.println(x);
  if (x<=10){
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    digitalWrite(blue,LOW);

  }
  if (x>10 && x<=20){
   digitalWrite(red,HIGH);
   digitalWrite(green,HIGH);
    digitalWrite(blue,LOW);
  }  if (x>20 ){
   digitalWrite(red,HIGH);
   digitalWrite(green,HIGH);
    digitalWrite(blue,HIGH);
  }
  
}
