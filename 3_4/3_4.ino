#include <Arduino.h>
#include <DHT.h>
#include <TM1637Display.h>
#define DHTPIN 5 
#define CLK 3
#define DIO 4
#define DHTTYPE DHT22 
DHT dht(DHTPIN, DHTTYPE);

const uint8_t DEGREES [ ] = {
SEG_A | SEG_B | SEG_G | SEG_F, // superscript o
SEG_A | SEG_F | SEG_E | SEG_D, // C
};

const uint8_t Huma [ ] = {
SEG_F | SEG_E | SEG_G | SEG_C | SEG_B // H,
};




TM1637Display display(CLK, DIO);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  display.setBrightness(0x0a); 

}


void loop() {
  // put your main code here, to run repeatedly:
   uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };

   int h = dht.readHumidity();
   int t = dht.readTemperature();
   bool lz = false ;
  display.showNumberDec(t, lz,2,0);
  display.setSegments(DEGREES,2,2);
  delay(1000);
  display.showNumberDec(h, lz,2,0);
  data[2] = display.encodeDigit(2);
   display.setSegments(data[2],1,2);
  display.setSegments(Huma,1,3);
  
  delay(1000);
  

  


  // All segments on
//  display.setSegments(data);
//  delay(TEST_DELAY);
  // All segments on
  //display.setSegments(data);
   //Serial.println("go");
//  display.showNumberDec(125,false, 3,1);

}
