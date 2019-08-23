#define BUTTON 0
#define R 2
int previous = LOW;
long time = 0;   
long debounce = 200; 
int state = 0; 
void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonValue = analogRead(BUTTON);
  if(buttonValue == HIGH  && previous == LOW && millis() - time > debounce) {
        state+=64;
        time = millis();
    }

    analogWrite(R, state);
    previous = buttonValue;

  
  

}
