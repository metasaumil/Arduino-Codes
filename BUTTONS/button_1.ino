int led = 13, butt = 7;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(butt, INPUT);
}

void loop() {
  if(digitalRead(butt)==HIGH) {
    digitalWrite(led, LOW);
    delay(3000);
    digitalWrite(led, HIGH);
  }
  else digitalWrite(led, HIGH);
}
