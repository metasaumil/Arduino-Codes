#include <Ultrasonic.h>
int rec = 2, trans = 3;
Ultrasonic ultrasonic(rec, trans);

void setup() {
  pinMode(rec, INPUT);
  pinMode(trans, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int distance = ultrasonic.distanceRead();
  Serial.print("distance = ");
  Serial.println(distance);
  delay(500);
}