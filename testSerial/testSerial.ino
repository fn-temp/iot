#include <Ultrasonic.h>
#define buzzer 3
#define r 2
Ultrasonic ultrasonic(6);

int num = 1000 ;
int dis ;
int checkPoint = 0 ;
int start = 0;
int times = -1 ;
void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);

}



void loop() {
  char inputText;
if (Serial.available() > 0) {    // is a character available?
    inputText = Serial.read();       // get the character
  
    if ((inputText == 's') || (inputText == 'S') || (inputText == 'e') || (inputText == 'E')) {
        times += 1 ;
        Serial.println(times);
    }

 if (inputText >= 'X') {
      num = Serial.parseInt();
      Serial.println(num);
            Serial.println(times);

    }
  
}
 if (times %2 == 0) {
  
          ultrasonic.MeasureInCentimeters();
          dis = ultrasonic.RangeInCentimeters;
          Serial.println(dis);
          delay(100); 
            if (dis < num) {
              analogWrite(buzzer,1);
              digitalWrite(r,HIGH);
              delay(100);
              analogWrite(buzzer,0);
              digitalWrite(r,LOW);
              delay(100);
              checkPoint++ ;
            }
  }

  if (checkPoint != 0) {
    analogWrite(buzzer,1);
              digitalWrite(r,HIGH);
              delay(100);
              analogWrite(buzzer,0);
              digitalWrite(r,LOW);
              delay(100);
  }
  
  if (times %2 != 0) {
          start = 0 ;
          checkPoint = 0 ;
          digitalWrite(r,LOW);
          analogWrite(buzzer,0);
   }
 
}
