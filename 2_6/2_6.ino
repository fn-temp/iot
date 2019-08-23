#define led 5
#define pot A1
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
    pinMode(led,OUTPUT);
  
  
}

void loop() {
//  // put your main code here, to run repeatedly:
  int readPod = analogRead(pot) /10;
  digitalWrite(led,HIGH);
  delay(readPod);
  digitalWrite(led,LOW);
  delay(readPod);
  digitalWrite(led,HIGH);
  delay(readPod);
  digitalWrite(led,LOW);
   delay(readPod);
  
  
  
  
}
