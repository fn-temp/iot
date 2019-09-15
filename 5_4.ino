#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#define pot A3
LiquidCrystal_I2C lcd(0x27,16,2);
uint8_t s[8] = {
  B00000,B00000,B00000, B00000,B00000,B00000,B00000,B00000
};
uint8_t five[8] = {
  B11111,B11111,B11111, B11111,B11111,B11111,B11111,B11111
};
void testLCD(int j){
        lcd.createChar(0,five);
        lcd.setCursor(j,0);
         lcd.write(0);
}
void deleteLCD(int j){
        lcd.createChar(0,s);
        lcd.setCursor(j,0);
         lcd.write(0);
         
}
void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
   lcd.begin();
   lcd.createChar(0,s);
   lcd.setCursor(0,0);
   lcd.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
   delay(100);
   int readPot = analogRead(pot)/63 ;
   Serial.println(readPot);
   if  (readPot ==0 ){
    
       lcd.createChar(0,s);
        lcd.setCursor(0,0);
        lcd.write(0);
   }
    if  (readPot==1 ){
      
      testLCD(0);
      testLCD(1);
      
      
   }
     if  (readPot==2 ){
       
          testLCD(0);
       testLCD(1);
       testLCD(2);
   }
    if  (readPot==3){
      
          testLCD(0);
        testLCD(1);
       testLCD(2);
     testLCD(3);
   }
    if  (readPot==4 ){
      
       testLCD(0);
       testLCD(1);
       testLCD(2);
       testLCD(3);
       testLCD(4);
   }
    if  (readPot==5){
      
       testLCD(0);
       testLCD(1);
       testLCD(2);
      testLCD(3);
      testLCD(4);
      testLCD(5);
   }
    if  (readPot==6 ){
      
       testLCD(0);
       testLCD(1);
       testLCD(2);
      testLCD(3);
      testLCD(4);
      testLCD(5);
     testLCD(6);
   }
    if  (readPot==7 ){
      
       testLCD(0);
       testLCD(1);
       testLCD(2);
      testLCD(3);
      testLCD(4);
      testLCD(5);
       testLCD(6);
      testLCD(7);
   } if  (readPot==8 ){
    
     testLCD(0);
     testLCD(1);
       testLCD(2);
      testLCD(3);
      testLCD(4);
      testLCD(5);
       testLCD(6);
      testLCD(7);
      testLCD(8);
   }
    if  (readPot==9 ){ 
      testLCD(0);
       testLCD(1);
       testLCD(2);
      testLCD(3);
      testLCD(4);
      testLCD(5);
       testLCD(6);
      testLCD(7);
      testLCD(8);
      testLCD(9);

   }
    if  (readPot==10){ 
      testLCD(0);
       
       testLCD(1);
       testLCD(2);
      testLCD(3);
      testLCD(4);
      testLCD(5);
       testLCD(6);
      testLCD(7);
      testLCD(8);
      testLCD(9);
      testLCD(10);
 
   }
    if  (readPot==11 ){ 
      
       testLCD(0);
         testLCD(1);
       testLCD(2);
      testLCD(3);
      testLCD(4);
      testLCD(5);
       testLCD(6);
      testLCD(7);
      testLCD(8);
      testLCD(9);
      testLCD(10);
       testLCD(11);

   } if  (readPot==12 ){
    
     testLCD(0);    
      testLCD(1);
       testLCD(2);
      testLCD(3);
      testLCD(4);
      testLCD(5);
       testLCD(6);
      testLCD(7);
      testLCD(8);
      testLCD(9);
      testLCD(10);
       testLCD(11);
      testLCD(12);

   }
    if  (readPot==13 ){ 
      
       testLCD(0);
       testLCD(1);
       testLCD(2);
      testLCD(3);
      testLCD(4);
      testLCD(5);
       testLCD(6);
      testLCD(7);
      testLCD(8);
      testLCD(9);
      testLCD(10);
       testLCD(11);
      testLCD(12);
      testLCD(13);
     
     
   }
   if  (readPot==14 ){
   testLCD(0);    
      testLCD(1);
       testLCD(2);
      testLCD(3);
      testLCD(4);
      testLCD(5);
       testLCD(6);
      testLCD(7);
      testLCD(8);
      testLCD(9);
      testLCD(10);
       testLCD(11);
      testLCD(12);
      
      testLCD(13);
      testLCD(14);

   } if  (readPot==15 ){
   testLCD(0);      
   testLCD(1);
       testLCD(2);
      testLCD(3);
      testLCD(4);
      testLCD(5);
       testLCD(6);
      testLCD(7);
      testLCD(8);
      testLCD(9);
      testLCD(10);
       testLCD(11);
      testLCD(12);
      testLCD(13);
      testLCD(14);
      testLCD(15);

   } if  (readPot==16 ){ 
     testLCD(0);
      testLCD(1);
       testLCD(2);
      testLCD(3);
      testLCD(4);
      testLCD(5);
       testLCD(6);
      testLCD(7);
      testLCD(8);
      testLCD(9);
      testLCD(10);
       testLCD(11);
      testLCD(12);
      testLCD(13);
      testLCD(14);
      testLCD(15);
      testLCD(16);
   }
   lcd.begin();
      
  
   
   

}
