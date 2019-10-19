#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#define pot A3
LiquidCrystal_I2C lcd(0x27,16,2);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
   lcd.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0, 0);
// print from 0 to 9:
for (int thisChar = 0; thisChar < 10; thisChar++) { 
  lcd.print(thisChar);
delay(500);
}
// set the cursor to (16,1):
lcd.setCursor(16, 1);
// set the display to automatically scroll: lcd.autoscroll();
// print from 0 to 9:
for (int thisChar = 0; thisChar < 10; thisChar++) {
lcd.print(thisChar);
delay(500); }
// turn off automatic scrolling
lcd.noAutoscroll();
// clear screen for the next loop: lcd.clear();


}
