//humanoid
#include <Servo.h>
// #include <SoftwareSerial.h>

// SoftwareSerial BTSerial(A0, A1);

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

// int IN1 = 2, IN2 = 3;
// int IN3 = 4, IN4 = 5;
int d, delayMs = 7;
unsigned long lastTimeBelow50 = 0;
bool wasAbove50 = false;

void setup() {
  Serial.begin(9600);
  // BTSerial.begin(9600);
  // for(int i = 2; i<=5; i++)
  //   pinMode(i, OUTPUT);
  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);
  servo4.attach(12);
  servo5.attach(13);
  servo1.write(0);
  servo2.write(0);
  servo3.write(90);
  servo4.write(0);
  servo5.write(0);
  dance();
  lastTimeBelow50 = millis();
}

void loop() {
  // if (BTSerial.available()) {
  //   char c = BTSerial.read();
  //   Serial.print(c);
  //   switch(c) {
  //     case 'S': stop(); break;
  //     case 'F': forward(); break;
  //     case 'B': backward(); break;
  //     case 'L': left(); break;
  //     case 'R': right(); break;
  //   }
  // }
  d = readUltrasonicDistance(7, 6) / 58.0;
  delay(500);
  if(d<10) {
    lastTimeBelow50 = millis(); 
    highfive();
  }
  else if(d<50) {
    lastTimeBelow50 = millis(); 
    salute();
  }
  else {
    if (!wasAbove50) {
      wasAbove50 = true;
      lastTimeBelow50 = millis();
    } 
    else if (millis() - lastTimeBelow50 >= 10000) {
      head();
      lastTimeBelow50 = millis();
    }
  }
}

long readUltrasonicDistance(int triggerPin, int echoPin) {
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  pinMode(echoPin, INPUT);
  long duration = pulseIn(echoPin, HIGH, 30000); // timeout 30ms

  if (duration == 0 || duration > 30000) return 30000; // treat as out of range
  return duration;
}

void sweepServo(Servo &s, int from, int to) {
  int step = from < to ? 1 : -1;
  for (int pos = from; pos != to + step; pos += step) {
    s.write(pos);
    delay(delayMs);
  }
}

void highfive() {
  sweepServo(servo4, 0, 120);
  delay(2000);
  sweepServo(servo4, 120, 0);
}

void salute() {
  sweepServo(servo4, 0, 120);
  sweepServo(servo5, 0, 120);
  delay(1000);
  sweepServo(servo5, 120, 0);
  sweepServo(servo4, 120, 0);
}

void head() {
  sweepServo(servo3, 90, 0);
  delay(500);
  sweepServo(servo3, 0, 180);
  delay(500);
  sweepServo(servo3, 180, 90);
}

void dance() {
  sweepServo(servo4, 0, 120);
  sweepServo(servo2, 0, 120);
  sweepServo(servo5, 0, 120);
  sweepServo(servo1, 0, 120);
  sweepServo(servo1, 120, 0);
  sweepServo(servo5, 120, 0);
  sweepServo(servo2, 120, 0);
  sweepServo(servo4, 120, 0);
}

// void forward() {
//   Serial.println("Forward");
//   digitalWrite(IN1, HIGH);
//   digitalWrite(IN2, LOW);
//   digitalWrite(IN3, HIGH);
//   digitalWrite(IN4, LOW);
// }

// void backward() {
//   Serial.println("Backward");
//   digitalWrite(IN1, LOW);
//   digitalWrite(IN2, HIGH);
//   digitalWrite(IN3, LOW);
//   digitalWrite(IN4, HIGH);
// }

// void right() {
//   Serial.println("Right");
//   digitalWrite(IN1, LOW);
//   digitalWrite(IN2, HIGH);
//   digitalWrite(IN3, HIGH);
//   digitalWrite(IN4, LOW);
// }

// void left() {
//   Serial.println("Left");
//   digitalWrite(IN1, HIGH);
//   digitalWrite(IN2, LOW);
//   digitalWrite(IN3, LOW);
//   digitalWrite(IN4, HIGH);
// }

// void stop() {
//   Serial.println("Stop");
//   digitalWrite(IN1, LOW);
//   digitalWrite(IN2, LOW);
//   digitalWrite(IN3, LOW);
//   digitalWrite(IN4, LOW);
// }