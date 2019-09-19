

char buffer[18];

int red, green, blue;
int RedPin = 6;
int GreenPin = 5;
int BluePin = 3;
int i = 0 ;
String ledInput[3] ;

void setup()
{
Serial.begin(9600);
//Serial.flush();
pinMode(RedPin, OUTPUT);
pinMode(GreenPin, OUTPUT);
pinMode(BluePin, OUTPUT);
}

void loop()
{
if (Serial.available() > 0) {
int index=0;
delay(100); // let the buffer fill up
int numChar = Serial.available();
if (numChar>15) {
numChar=15;
}
while (numChar--) {
buffer[index++] = Serial.read();
}
splitString(buffer);
int R = ledInput[0].toInt();
int G = ledInput[1].toInt();
int B = ledInput[2].toInt();

//Serial.println(ledInput[0]);
//Serial.println(R);

analogWrite(RedPin,R);
analogWrite(GreenPin,G);
analogWrite(BluePin,B);
i=0;
}

}
void splitString(char* data) {
Serial.print("Data entered: ");
Serial.println(data);
char* parameter;
parameter = strtok (data, " ,");
while (parameter != NULL) {
//  Serial.println(parameter);
if (parameter == "-1") {
  i++;
}
 else {
  ledInput[i]=parameter; 
  i++;
 }
 
  parameter = strtok (NULL, " ,");
  
   }
// Clear the text and serial buffers
for (int x=0; x<16; x++) {
buffer[x]='\0';
}
Serial.flush();
i = 0 ;
}
