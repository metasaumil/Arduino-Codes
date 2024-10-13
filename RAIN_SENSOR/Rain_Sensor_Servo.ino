#include <Servo.h>
Servo servo;

void setup() {
  // put your setup code here, to run once:
  servo.attach(13);
  servo.write(0);
  pinMode(2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(2) == 0) 
   servo.write(90);
  else 
   servo.write(0);
}
