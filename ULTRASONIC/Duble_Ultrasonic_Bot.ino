#include <Ultrasonic.h>
int n1 = 2, n2 = 3, n3 = 4, n4 = 5, rec_1 = 6, trans_1 = 7, rec_2 = 8, trans_2 = 9;

long duration;

void setup() {
  pinMode(rec_1, INPUT);
  pinMode(trans_1, OUTPUT);
  pinMode(rec_2, INPUT);
  pinMode(trans_2, OUTPUT);
  pinMode(n1, OUTPUT);
  pinMode(n2, OUTPUT);
  pinMode(n3, OUTPUT);
  pinMode(n4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  forward();
  int right_distance = calDis(trans_1, rec_1);
  int left_distance = calDis(trans_2, rec_2);
  Serial.print("Right distance: ");
  Serial.print(right_distance); // Print the output in serial monitor
  Serial.println(" cm");
  Serial.print("Left distance: ");
  Serial.print(left_distance); // Print the output in serial monitor
  Serial.println(" cm");
  if (right_distance < 20) {
    stop();
    delay(1000);
    if(left_distance<20) {
      backward();
      delay(1000);
    }
    left();
    delay(1000);
  }
  if(left_distance<20) {
    stop();
    delay(1000);
    if(right_distance<20) {
      backward();
      delay(1000);
    }
    right();
    delay(1000);  
  }
  delay(500);
}

int calDis(int trans, int rec) {
  digitalWrite(trans, LOW);
  delayMicroseconds(2);
  digitalWrite(trans, HIGH);
  delayMicroseconds(10);
  digitalWrite(trans, LOW);
  duration = pulseIn(rec, HIGH);
  return duration * 0.0344 / 2;
}

void forward() {
  digitalWrite(n1, HIGH);
  digitalWrite(n2, LOW);
  digitalWrite(n3, HIGH);
  digitalWrite(n4, LOW);
}

void backward() {
  digitalWrite(n1, LOW);
  digitalWrite(n2, HIGH);
  digitalWrite(n3, LOW);
  digitalWrite(n4, HIGH);
}

void left() {
  digitalWrite(n1, HIGH);
  digitalWrite(n2, LOW);
  digitalWrite(n3, LOW);
  digitalWrite(n4, HIGH);
}

void right() {
  digitalWrite(n1, LOW);
  digitalWrite(n2, HIGH);
  digitalWrite(n3, HIGH);
  digitalWrite(n4, LOW);
}

void stop() {
  digitalWrite(n1, LOW);
  digitalWrite(n2, LOW);
  digitalWrite(n3, LOW);
  digitalWrite(n4, LOW);
}
