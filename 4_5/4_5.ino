unsigned long cnt = 0;
unsigned long sum = 0;
int value;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long elapsedTime = millis();
  value = analogRead(A0);
  if (cnt<100){
    sum+=value ;
    cnt++;
  }
  else {
    Serial.println(elapsedTime);
     Serial.print("sum:");
      Serial.println(sum);
    Serial.println(sum/cnt);
  delay(100);
    cnt = 0 ; 
    sum=0;
  }
}
