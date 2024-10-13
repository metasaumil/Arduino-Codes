int del = 1500, run_time = 3000;
void setup() {
    for(int i = 0; i<8; i++)
        pinMode(i, OUTPUT);
}

void loop() {
  long startTime = millis();
  long duration = 3000;

  while (millis() - startTime < duration) {
        pattern_1();
  }
  delay(del);
  duration += del+run_time;

  while (millis() - startTime < duration) {
        pattern_2();
  }
  delay(del);
  duration += del+run_time;

  while (millis() - startTime < duration) {
        pattern_3();
  }
  delay(del);
  duration += del+run_time;
  
  while (millis() - startTime < duration) {
        pattern_4();
  }
  delay(del);
  duration += del+run_time;

  while (millis() - startTime < duration) {
        pattern_5();
  }
  delay(del);
}

void pattern_1() {
  //line and reverse
  for(int i = 1; i<=8; i++) {
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i, LOW);
  }
  for(int i = 7; i>= 2; i--) {
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i, LOW);
  }
}

void pattern_2() {
  //alternate
  for(int i = 1; i<=8; i = i+2) {
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i, LOW);
  }
  for(int i = 2; i<=8; i = i+2) {
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i, LOW);
  }
}

void pattern_3() {
  //towards center
  for(int i = 1; i<=4; i++) {
    digitalWrite(i, HIGH);
    digitalWrite(9-i, HIGH);
    delay(100);
    digitalWrite(i, LOW);
    digitalWrite(9-i, LOW);
  }
}

void pattern_4() {
  //increasing
  for(int i = 1; i<=8; i++) {
    digitalWrite(i, HIGH);
    delay(100);
  }
  for(int i = 8; i>= 1; i--) {
    digitalWrite(i, LOW);
    delay(100);
  }
}

void pattern_5() {
  //center out
  for(int i = 4; i>=1; i--) {
    digitalWrite(i, HIGH);
    digitalWrite(9-i, HIGH);
    delay(100);
    digitalWrite(i, LOW);
    digitalWrite(9-i, LOW);
  }
}