#define R 3
#define G 5
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //int R = 4;
  pinMode(R,OUTPUT);
  pinMode(G,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    digitalWrite(R,HIGH);
    delay(1000);
    digitalWrite(R,LOW);
    delay(1000);
     digitalWrite(G,HIGH);
    delay(1000);
    digitalWrite(G,LOW);
    delay(1000);

  }
  
  
