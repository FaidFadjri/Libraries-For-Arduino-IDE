int sensor = A0;
int sensorValue = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(7, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(sensor);
  Serial.println(sensorValue);
  float voltage = sensorValue * (5.0/1023);
  Serial.println(voltage);

  if(voltage<=1.5){
    digitalWrite(7, HIGH);
  }else{
    digitalWrite(7, LOW);
  }
  delay(200);

}
