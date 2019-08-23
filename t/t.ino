#define BOTTON 7
#define R 3
unsigned long timePrev;
int ledState = 0;


void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
  pinMode(R,OUTPUT);
   pinMode(BOTTON,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:


    unsigned long timeNow, timeElapsed;
    timeNow = millis();
    timeElapsed = timeNow - timePrev;
    if (timeElapsed > 1000) {
    timePrev = timeNow;
    ledState = 1 - ledState; //toggle state
    digitalWrite(R, ledState); //turn LED on after 1 sec
    }
    }




}
