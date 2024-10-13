#include <Servo.h>
Servo servo_1;
Servo servo_2;
Servo servo_3;
Servo servo_4;

void setup() {
  // put your setup code here, to run once:
  servo_1.attach(5);
  servo_2.attach(4);
  servo_3.attach(3);
  servo_4.attach(2);
  servo_1.write(0);
  servo_2.write(0);
  servo_3.write(0);
  servo_4.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i<=60; i++) {
    servo_1.write(i);
    delay(5);
  }
  delay(10);
  for(int i = 0; i<=60; i++) {
    servo_2.write(i);
    delay(5);
  }
  delay(10);
  for(int i = 0; i<=60; i++) {
    servo_3.write(i);
    delay(5);
  }
  delay(10);
  for(int i = 0; i<=60; i++) {
    servo_4.write(i);
    delay(5);
  }
  delay(10);
  for(int i = 60; i>=0; i--) {
    servo_1.write(i);
    delay(5);
  }
  delay(10);
  for(int i = 60; i>=0; i--) {
    servo_2.write(i);
    delay(5);
  }
  delay(10);
  for(int i = 60; i>=0; i--) {
    servo_3.write(i);
    delay(5);
  }
  delay(10);
  for(int i = 60; i>=0; i--) {
    servo_4.write(i);
    delay(5);
  }
  delay(10);
}
