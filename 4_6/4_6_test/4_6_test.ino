#include <Ultrasonic.h>
#define buzzer 3
#define r 2
#define button 7
Ultrasonic ultrasonic(6);

int start = 0;
int dis = 0 ;
int times = -1 ;
void setup() {
  Serial.begin(9600);
  pinMode(r,OUTPUT);
  pinMode(button,INPUT);

}

void loop() {
  
  delay(100);
  if (digitalRead(button) == 1) {
      times += 1 ;
  }

  if (times %2 == 0) {
        start = 1 ;  
  }
  if (times %2 != 0) {
        start = 0 ;  
  }

  
Serial.println(start);
Serial.println("---------");
Serial.println(times);

  if (start == 1) {
    Serial.println(start);
    ultrasonic.MeasureInCentimeters();
    dis = ultrasonic.RangeInCentimeters;
    Serial.println(dis);
    delay(100); 
    if (dis < 50) {
      analogWrite(buzzer,2);
    digitalWrite(r,HIGH);
    delay(100);
    analogWrite(buzzer,0);
    digitalWrite(r,LOW);
    delay(100);
    }   
  }

  if (start == 0) {
    digitalWrite(r,LOW);
    analogWrite(buzzer,0);
  }
   
}
