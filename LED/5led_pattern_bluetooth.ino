int l1 = 13, l2 = 12, l3 = 11, l4 = 10, l5 = 9;
char command;

void setup() {
pinMode(l1, OUTPUT);
pinMode(l2, OUTPUT);
pinMode(l3, OUTPUT);
pinMode(l4, OUTPUT);
pinMode(l5, OUTPUT);
Serial.begin(9600); // Start serial communication with the Bluetooth module
}
void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();
    if(command == '1')
      blink1();
    if(command == '2')
      blink2();
    if(command == '3')
      blink3();
    if(command == '4')
      blink4();
    if(command == '5')
      blink5();
    if(command == '0')
      stop();

  }
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

void stop() {
digitalWrite(l1, LOW);
digitalWrite(l2, LOW);
digitalWrite(l3, LOW);
digitalWrite(l4, LOW);
digitalWrite(l5, LOW);
}