#include <SoftwareSerial.h>

// Connect HC-05 TX to Arduino pin 10, and RX to pin 11
SoftwareSerial BTSerial(6, 7); // RX, TX

int IN1 = 2, IN2 = 3;
int IN3 = 4, IN4 = 5;

void setup() {
  Serial.begin(9600);      // Serial Monitor
  BTSerial.begin(9600);    // HC-05 default baud rate
  Serial.println("Waiting for data from HC-05...");
  for(int i = 2; i<=5; i++)
    pinMode(i, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  if (BTSerial.available()>0) {
    char c = BTSerial.read();  // Read character from HC-05
    Serial.print(c);           // Print to Serial Monitor
    switch(c) {
      case 'S': stop(); break;
      case 'F': forward(); break;
      case 'B': backward(); break;
      case 'L': left(); break;
      case 'R': right(); break;
      case 'Y': buzz(); break;
    }
  }
}

void buzz() {
  tone(11, 440, 200);
  delay(500);
  tone(11, 440, 500);
  delay(500);        
}

void forward() {
  Serial.println("Forward");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward() {
  Serial.println("Backward");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left() {
  Serial.println("Left");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void right() {
  Serial.println("Right");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stop() {
  Serial.println("Stop");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}