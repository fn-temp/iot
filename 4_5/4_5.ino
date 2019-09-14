#define red 2
int Sensor = A0;
int clap = 0;
long detection_range_start = 0;
long detection_range = 0;
boolean status_lights = false;
int time = 0 ;

void setup() {
  Serial.begin(9600);
  //pinMode(Sensor, INPUT);
  pinMode(red,OUTPUT);
}

void loop() {
   // --- test noise ---
//  int status_sensor = analogRead(Sensor);
//  Serial.println(status_sensor);
//  delay(180);

  delay(30);
int status_sensor = analogRead(Sensor);
if (status_sensor >= 500) {

    clap ++ ;
}
//if (clap ==2 && time ==0){
//  digitalWrite(red,HIGH);
//  time++;
//  clap=0;
//}else if (clap ==2 && time ==1){
//  digitalWrite(red,LOW);
//  time=0;
//  clap=0;
//}
//if (status_sensor > 0) {
//    if (clap == 0) {
//       if (status_sensor >=550) {
//        clap+=100 ;
//        detection_range_start = detection_range = millis(); 
//    Serial.println("loop 1");
//       }
//    }
//    
//    else if (clap > 1 && status_sensor >=550 && millis()-detection_range  >= 40) {
//      detection_range = millis();
//        clap+=300;
//         Serial.println("loop 2");
//    }
//
//
//}
         Serial.print("clap -> ");
    Serial.println(clap);
Serial.println(status_sensor);


//if (millis()-detection_range_start >= 700) {
//    if (clap == 2) {
//      if (!status_lights) {
//        status_lights = true;
//        digitalWrite(red, HIGH);
//      }
//      else if (status_lights) {
//        status_lights = false;
//        digitalWrite(red, LOW);
//      }
//    }
//        clap = 0;
//  }
}
