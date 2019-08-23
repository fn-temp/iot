#include <DHT.h>
#include <TM1637Display.h>

#define DHTPIN 2 
#define DHTTYPE DHT22 
#define CLK 2
#define DIO 3
TM1637Display display(CLK, DIO);
DHT dht(DHTPIN, DHTTYPE);


void setup() {
  // put your setup code here, to run once:
   dht.begin();
   display.setBrightness(10);

}

void loop() {
  // put your main code here, to run repeatedly:
  int t = dht.readTemperature();
   int k;
   uint8_t data[] = { 0, 0, 0, 0};
   display.setSegments(data,4,0);
}
