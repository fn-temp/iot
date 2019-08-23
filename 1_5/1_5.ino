#define BOTTON 7
#define TOUCH 4
#define R 3
#define G 5
int ledState = 0;
unsigned long timePrev;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(R,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(BOTTON,INPUT);
  pinMode(TOUCH,INPUT);

}
void loop() {
  // put your main code here, to run repeatedly:
  unsigned long timeNow, timeElapsed;
  timeNow = millis();
  timeElapsed = timeNow-timePrev;
  int buttonValue = digitalRead(BOTTON);
  int touchValue = digitalRead(TOUCH);
  if (buttonValue == LOW && touchValue == LOW){
     digitalWrite(R,LOW);
     digitalWrite(G,LOW);
  } 
  if(buttonValue == HIGH && touchValue == HIGH) {
     digitalWrite(R,HIGH);
     digitalWrite(G,HIGH);
  }
  if (buttonValue  != touchValue){
    if (buttonValue == HIGH){
      digitalWrite(G,LOW);
      if (timeElapsed > 1000) {
      timePrev = timeNow;
      ledState = 1 - ledState; //toggle state
      digitalWrite(R, ledState); //turn LED on after 1 sec
      }
      
    }if (touchValue == HIGH){
       digitalWrite(R,LOW);
      if (timeElapsed > 1000) {
      timePrev = timeNow;
      ledState = 1 - ledState; //toggle state
      digitalWrite(G, ledState); //turn LED on after 1 sec
    }
      
    }
  }

 

}
