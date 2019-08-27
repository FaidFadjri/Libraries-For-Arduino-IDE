#include <Servo.h>
Servo Servoku;
void setup() {
  // put your setup code here, to run once:
  Servoku.attach(9);
 

}

void loop() {
  // put your main code here, to run repeatedly:
  Servoku.write(10);
  delay(1000);
  Servoku.write(100);
  delay(1000);

}
