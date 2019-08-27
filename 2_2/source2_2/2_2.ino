#define BUTTON 0
#define LED 2

int brightness = 0;
int count = 0;
void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  //analogWrite(led, brightness);

  if (digitalRead(BUTTON)== HIGH) {
    count++ ;
    brightness+=62;
  }

  if ((count > 0) && (count <= 4)) {
    analogWrite(LED, brightness);
  }

  if (count > 4) {
    brightness = 0 ;
    count = 0;
    analogWrite(LED, brightness);
  }
    
}
