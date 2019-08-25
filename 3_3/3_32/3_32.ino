#include <ChainableLED.h>
#include <DHT.h>

#define DHTPIN 5 
#define DHTTYPE DHT22 
#define NUM_LEDS  7

ChainableLED leds(7, 8, NUM_LEDS);
DHT dht(DHTPIN, DHTTYPE);

float check = 0 ;
int blue = 255;
int red = 139;

void setup() {
 Serial.begin(9600);
 dht.begin();
 leds.init();
 
}

void loop() {
  float t = dht.readTemperature();
  
  Serial.println(t);
    Serial.println(check);
     Serial.println("---------");
  delay(500);
  

//  int rate = map(t,0,100,0,255);

  if (check > t) {
    red -=35;
    blue +=35 ;
         Serial.println("------check > t---");

    }  


  if (t > check) {
    red +=35;
    blue -= 35;
             Serial.println("------t > check---");

  }

  if (blue > 255) {
    blue = 255;
  }

  if (blue < 0) {
    blue = 0;
  }

    if (red > 255) {
    red = 255;
  }

  if (red < 0) {
    red = 0;
  }
  leds.setColorRGB(0,red,0,blue); 
  check = t ;
   Serial.println(red);
    Serial.println(blue);
    Serial.println("----*******--");
    delay(500);
      

}
