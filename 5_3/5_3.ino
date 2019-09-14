#include <ChainableLED.h>
const int SW_pin = 0; 
const int X_pin = A0; 
const int Y_pin = A1; 
#define NUM_LEDS  7

ChainableLED leds(7, 8, NUM_LEDS);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  leds.init();
  leds.setColorRGB(0,255,0,0); 

}

void loop() {
  // put your main code here, to run repeatedly:
  //  Serial.print("Switch:  ");
//  Serial.print(digitalRead(SW_pin));
//  Serial.print(" | ");
  Serial.print("X-axis: ");
  int x = analogRead(X_pin);
  Serial.print(x);
  Serial.print(" | ");
  Serial.print("Y-axis: ");
  int y= analogRead(Y_pin);
  Serial.print(y);
  Serial.println(" | ");
  if (y>=510  ){
    if (x >=750) {
  }
  }
  delay(200);

}
