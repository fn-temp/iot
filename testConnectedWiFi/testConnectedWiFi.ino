#include <ESP8266WiFi.h> 
#define LED D3

const char* ssid = "nn"; 
const char* pass = "noon2542"; 

unsigned char status_led=0;
WiFiServer server(80);

void setup () {
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  
  WiFi.begin(ssid, pass); 

  while (WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print("."); 
    
  } 

  server.begin();
  Serial.println(""); 
  Serial.println("Wi-Fi connected");
  Serial.print("IP Address : ");
  Serial.println(WiFi.localIP());
}

void loop () { 
}
