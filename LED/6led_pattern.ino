int l1 = 13, l2 = 12, l3 = 11, l4 = 10, l5 = 9, l6 = 8;

void setup() {
  // put your setup code here, to run once:
pinMode(l1, OUTPUT);
pinMode(l2, OUTPUT);
pinMode(l3, OUTPUT);
pinMode(l4, OUTPUT);
pinMode(l5, OUTPUT);
pinMode(l6, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(l1, HIGH);
digitalWrite(l6, HIGH);
digitalWrite(l2, LOW);
digitalWrite(l3, LOW);
digitalWrite(l4, LOW);
digitalWrite(l5, LOW);
delay(100);

digitalWrite(l2, HIGH);
digitalWrite(l5, HIGH);
digitalWrite(l1, LOW);
digitalWrite(l3, LOW);
digitalWrite(l4, LOW);
digitalWrite(l6, LOW);
delay(100);

digitalWrite(l3, HIGH);
digitalWrite(l4, HIGH);
digitalWrite(l1, LOW);
digitalWrite(l2, LOW);
digitalWrite(l5, LOW);
digitalWrite(l6, LOW);
delay(100);

digitalWrite(l2, HIGH);
digitalWrite(l5, HIGH);
digitalWrite(l3, LOW);
digitalWrite(l1, LOW);
digitalWrite(l4, LOW);
digitalWrite(l6, LOW);
delay(100);


}
