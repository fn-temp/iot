#include <Ultrasonic.h>
#define buzzer 3
#define r 2
#define button 7
Ultrasonic ultrasonic(6);
int x,count =0;
 boolean start= false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(r,OUTPUT);
  pinMode(button,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   int a = digitalRead(button);
  if ( a == 1 ){
     start = true;
  }else if (a ==1 && count %2!=0 ){
     start = false;
      Serial.println(start);
     digitalWrite(r,LOW);
     analogWrite(buzzer,0);
     count++;
  }
  ultrasonic.MeasureInCentimeters();
  x = ultrasonic.RangeInCentimeters;
  Serial.println(x);
  delay(100); 
  if (start == true && x<50 && count%2==0 ){
    
    analogWrite(buzzer,10);
    digitalWrite(r,HIGH);
    delay(100);
    analogWrite(buzzer,0);
    digitalWrite(r,LOW);
    delay(100);
    count++;
    
 }
 
Serial.println(start);
}
