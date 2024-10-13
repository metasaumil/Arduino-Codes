int l1 = 13, l2 = 12, l3 = 11, l4 = 10, l5 = 9;
void setup() {
pinMode(l1, OUTPUT);
pinMode(l2, OUTPUT);
pinMode(l3, OUTPUT);
pinMode(l4, OUTPUT);
pinMode(l5, OUTPUT);
}
void loop() {
blink1();
delay(100);
blink2();
delay(100);
blink3();
delay(100);
blink4();
delay(100);
blink5();
delay(100);
blink4();
delay(100);
blink3();
delay(100);
blink2();
delay(100);
}

void blink1() {
digitalWrite(l1, HIGH);
digitalWrite(l2, LOW);
digitalWrite(l3, LOW);
digitalWrite(l4, LOW);
digitalWrite(l5, LOW);

}

void blink2() {
  
digitalWrite(l1, LOW);
digitalWrite(l2, HIGH);
digitalWrite(l3, LOW);
digitalWrite(l4, LOW);
digitalWrite(l5, LOW);
}

void blink3() {
  
digitalWrite(l1, LOW);
digitalWrite(l2, LOW);
digitalWrite(l3, HIGH);
digitalWrite(l4, LOW);
digitalWrite(l5, LOW);
}

void blink4() {
  
digitalWrite(l1, LOW);
digitalWrite(l2, LOW);
digitalWrite(l3, LOW);
digitalWrite(l4, HIGH);
digitalWrite(l5, LOW);
}

void blink5() {
  
digitalWrite(l1, LOW);
digitalWrite(l2, LOW);
digitalWrite(l3, LOW);
digitalWrite(l4, LOW);
digitalWrite(l5, HIGH);
}