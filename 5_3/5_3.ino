#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ChainableLED.h>
#define clkPin 7
#define dataPin 8

ChainableLED led(clkPin, dataPin, 1);
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  led.init();
  lcd.begin();
  setDisplay();
}
int state= 0,timePrev=0;
int color[3];
void loop() {
  // put your main code here, to run repeatedly:
  int x,y,timeElap;
  x = analogRead(A0);  
  x = map(x,0,900,0,255);
  Serial.print("x" );
  Serial.println(x );
  y = analogRead(A1);  
  y = map(y,0,900,0,255);
  Serial.print("y" );
  Serial.println(y );
  timeElap = millis();


  //switch colour
  if(timeElap-timePrev>300){
    timePrev = timeElap;
    if(x <= 85){
      state--;
      if(state<0){
        state=2;
      }
      setDisplay();
    }
    else if(x >= 170){
      state++;
      if(state>2){
        state = 0;
      }
      setDisplay();
    }
  }

  //adjust colour
  if(y>=170){
    if(color[state]>=254){
      color[state]=254;
    }
    color[state]++;
    setDisplay();
  }
  if(y<=170){
    if(color[state]<=1){
      color[state]=1;
    }
    color[state]--;
    setDisplay();
  }
  led.setColorRGB(0,color[0],color[1],color[2]);
}

void setDisplay(){
  lcd.clear();
  lcd.print("R:");
  lcd.print(color[0]);
  lcd.setCursor(5,0);
  lcd.print("G:");
  lcd.print(color[1]);
  lcd.setCursor(11,0);
  lcd.print("B:");
  lcd.print(color[2]);
  if(state == 0){lcd.setCursor(0,1);}
  else if(state == 1){lcd.setCursor(5,1);}
  else{lcd.setCursor(11,1);}
  lcd.print("^");
}
