#include <Servo.h>
#include <Ultrasonic.h>

Servo servo; // Create a servo object to control the servo motor
int pos = 0, rec = 9, trans = 10,  n1 = 2, n2 = 3, n3 = 4, n4 = 5, distance, front, right_max, right_dis, left_max, left_dis; // Initialize the servo position
long duration;

void setup() {
  servo.attach(8); // Attach the servo to digital pin 9
  servo.write(90); // Rotate the servo to 0 degrees immediately
  pinMode(rec, INPUT);
  pinMode(trans, OUTPUT);
  pinMode(n1, OUTPUT);
  pinMode(n2, OUTPUT);
  pinMode(n3, OUTPUT);
  pinMode(n4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Rotate slowly from 0 degrees to 180 degrees, one degree at a time
  forward();
  front = calDis();
  Serial.print("Front distance = ");
  Serial.println(front);
  if(front<30) {
    stop();
    delay(500);
    right_max = 0;
    right_dis = 0;
    for(int i = 0; i<=60; i++) {
      servo.write(i);
      delay(10);
      right_dis = calDis();
      if(right_dis>right_max)
        right_max = right_dis;
    }
    left_max = 0;
    left_dis = 0;
    for(int i = 120; i<=180; i++) {
      servo.write(i);
      delay(10);
      left_dis = calDis();
      if(left_max>right)
        left_max = left_dis;
    }
    servo.write(90);
    if(right_max>left_max && right_max>30) {
      right();
      delay(300);
    }
    else if(left_max>right_max && left_max>30) {
      left();
      delay(300);
    }
    else {
      backward();
      delay(1000);
    }
  }
  Serial.print("Right distance = ");
  Serial.println(right_max);
  Serial.print("Left distance = ");
  Serial.println(left_max);
  delay(500);
}

int calDis() {
  int start_time = millis();
  digitalWrite(trans, LOW);
  int current_time = millis();
  if(current_time-start_time>5) {
    return 100;
  }
  delayMicroseconds(2);
  current_time = millis();
  if(current_time-start_time>5) {
    return 100;
  }
  digitalWrite(trans, HIGH);
  current_time = millis();
  if(current_time-start_time>5) {
    return 100;
  }
  delayMicroseconds(10);
  current_time = millis();
  if(current_time-start_time>5) {
    return 100;
  }
  digitalWrite(trans, LOW);
  current_time = millis();
  if(current_time-start_time>5) {
    return 100;
  }
  duration = pulseIn(rec, HIGH);
  current_time = millis();
  if(current_time-start_time>5) {
    return 100;
  }
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