#define red 2
int Sensor = A1;
int clap = 0;
long detection_range_start = 0;
long detection_range = 0;
boolean status_lights = false;
int readyTime = 0 ;
int times = 0 ;

void setup() {
  Serial.begin(9600);
  pinMode(Sensor, INPUT);
  pinMode(red,OUTPUT);
}

void loop() {
//      Serial.println(analogRead(Sensor) );
int sum = 0 ;
sum+=analogRead(Sensor);
sum+=analogRead(Sensor);
sum+=analogRead(Sensor);
sum+=analogRead(Sensor);
sum+=analogRead(Sensor);
//Serial.print("sum --------");
//Serial.println(sum);
//Serial.print("sum / 5 --------");
//Serial.println(sum/5);


  if (sum/5 >= 450 ) {
//    digitalWrite(red,HIGH);
    readyTime += 1;
      Serial.println("+++++++++1111111111111111");

    delay(400);

  }



  if (readyTime == 2) {
    digitalWrite(red,HIGH);
  }

  if (readyTime == 4) {
       digitalWrite(red,LOW);
// 
  }

  if (readyTime > 4) {
    readyTime = 0 ;
  }
//
//  Serial.println(sound);
 Serial.print("clap -> ");
    Serial.println(readyTime);
    delay(5);
}
