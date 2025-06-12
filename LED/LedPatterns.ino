int ledArray[] = {3, 5, 6, 9, 10, 11};
int time = 800;

void setup() {
  Serial.begin(9600);
  for(int i = 0; i<6; i++)
    pinMode(ledArray[i], OUTPUT);
}

int selectedPattern = 0;

void loop() {
  if (Serial.available() > 0) {
    int input = Serial.parseInt();
    
    while (Serial.available() > 0) Serial.read();

    if (input > 0 && input <= 10) {
      selectedPattern = input;
      Serial.print("Pattern selected: ");
      Serial.println(selectedPattern);
      off();  

      while (Serial.available() == 0) {
        switch (selectedPattern) {
          case 1: pattern1(); break;
          case 2: pattern2(); break;
          case 3: pattern3(); break;
          case 4: pattern4(); break;
          case 5: pattern5(); break;
          case 6: pattern6(); break;
          case 7: pattern7(); break;
          case 8: pattern8(); break;
          case 9: on(); break;
          case 10: off(); break;
          default: break;
        }
      }
    }
  }
}

void pattern1() {
  for(int i = 0; i<6; i++)
    pwm(ledArray[i]);
}

void pwm(int ledPin) {
  for (int brightness = 0; brightness <= 255; brightness++) {
    analogWrite(ledPin, brightness);
    delay(1);
  }
  for (int brightness = 255; brightness >= 0; brightness--) {
    analogWrite(ledPin, brightness);
    delay(1);
  }
}

void pattern2() {
  for(int i = 0; i<6; i++) {
    digitalWrite(ledArray[i], HIGH);
    delay(100);
    digitalWrite(ledArray[i], LOW);
  }
}

void pattern3() {
  for(int i = 0; i<3; i++) {
    digitalWrite(ledArray[i], HIGH);
    digitalWrite(ledArray[5-i], HIGH);
    delay(250);
  }
  for(int i = 0; i<3; i++) {
    digitalWrite(ledArray[i], LOW);
    digitalWrite(ledArray[5-i], LOW);
    delay(250);
  }
}

void pattern4() {
  for (int brightness = 0; brightness <= 255; brightness++) {
    for(int i = 0; i<6; i++)
      analogWrite(ledArray[i], brightness);
      delay(10);
  }
  for (int brightness = 255; brightness >= 0; brightness--) {
    for(int i = 0; i<6; i++)
      analogWrite(ledArray[i], brightness);
      delay(10);
  }
}

void on() {
  for(int i = 0; i<6; i++)
    digitalWrite(ledArray[i], HIGH);
}

void off() {
  for(int i = 0; i<6; i++)
    digitalWrite(ledArray[i], LOW);
}

void pattern5() {
  on();
  delay(200);
  off();
  delay(70);
  on();
  delay(200);
  off();
  delay(1000);
}
void pattern6() {
  for(int i = 0; i < 6; i++) {
    digitalWrite(ledArray[i], HIGH);
    delay(100);
    digitalWrite(ledArray[i], LOW);
  }
  for(int i = 6; i > 0; i--) {
    digitalWrite(ledArray[i], HIGH);
    delay(100);
    digitalWrite(ledArray[i], LOW);
  }
}

void pattern7() {
    for(int i = 0; i < 3; i++) {
      digitalWrite(ledArray[2 - i], HIGH);
      digitalWrite(ledArray[3 + i], HIGH);
      delay(time);
    }
    off();
    if(time<20)
      time -= 1;
    else if(time<50)
      time -= 5;
    else if(time<100)
      time -= 20;
    else if(time<300)
      time -= 50;
    else
      time -= 100;
    if (time <= 0) {
      time = 800;
      off();
      delay(time);
    }
}

void pattern8() {
  for(int i = 0; i < 20; i++) {
    int randomLED = random(0, 6);
    digitalWrite(ledArray[randomLED], HIGH);
    delay(100);
    digitalWrite(ledArray[randomLED], LOW);
  }
}
