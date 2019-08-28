const int lampu = 7;
const int sound = 8;
#include <Servo.h>
Servo Servoku;

#define NOTE_C4 262
void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);
  pinMode(lampu, OUTPUT);
  pinMode(sound, OUTPUT);
  Servoku.attach(9);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  delay(1);
  if(sensorValue<=100){
    digitalWrite(lampu, HIGH);
    
    tone(sound, NOTE_C4);
    delay(250);
    noTone(sound);
    
    Servoku.write(0);
    
    
    
    
    }else{
    digitalWrite(lampu, LOW);
    noTone(sound);
    Servoku.write(100);
    delay(250);
   }
}
  
