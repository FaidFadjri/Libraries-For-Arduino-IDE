int pinLED = 8;
int pinPIR = 7;
int statusPin = 0;
#define NOTE_C4 262

const int speaker = 9;
void setup() {
  // put your setup code here, to run once:
  pinMode(pinLED, OUTPUT);
  pinMode(pinPIR, INPUT);
  Serial.begin(9600);
  pinMode(speaker, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  statusPin = digitalRead(pinPIR);
  if(statusPin == HIGH){
    digitalWrite(pinLED, HIGH);
    Serial.println("Ada Gerakan");
    tone(speaker, NOTE_C4);
    delay(250);
    noTone(speaker);
    delay(250);
  }else{
    digitalWrite(pinLED, LOW);
    Serial.println("kondisi aman");
    noTone(speaker);
  }
  

}
