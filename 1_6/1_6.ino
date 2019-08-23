#define BOTTON 7
#define R 3
int previous = LOW;
long time = 0;   
long debounce = 200; 
int state = HIGH; 
void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
  pinMode(R,OUTPUT);
  pinMode(BOTTON,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 int buttonValue = digitalRead(BOTTON);

 if(buttonValue == HIGH  && previous == LOW && millis() - time > debounce) {
        state = !state;
        time = millis();
    }

    digitalWrite(R, state);
     previous = buttonValue;


}
