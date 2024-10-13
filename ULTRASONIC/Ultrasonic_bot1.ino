#include <Ultrasonic.h>
int n1 = 2, n2 = 3, n3 = 4, n4 = 5, rec = 6, trans = 7;

long duration; // Variable to store time taken to the pulse
               // to reach receiver
int distance;
Ultrasonic ultrasonic(rec, trans);

void setup() {
  pinMode(rec, INPUT);
  pinMode(trans, OUTPUT);
  pinMode(n1, OUTPUT);
  pinMode(n2, OUTPUT);
  pinMode(n3, OUTPUT);
  pinMode(n4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  forward();
  digitalWrite(trans, LOW);
    delayMicroseconds(2); // wait for 2 ms to avoid
                          // collision in serial monitor

    digitalWrite(
        trans,
        HIGH); // turn on the Trigger to generate pulse
    delayMicroseconds(
        10); // keep the trigger "ON" for 10 ms to generate
             // pulse for 10 ms.

    digitalWrite(trans,
                 LOW); // Turn off the pulse trigger to stop
                       // pulse generation

    // If pulse reached the receiver rec
    // become high Then pulseIn() returns the
    // time taken by the pulse to reach the
    // receiver

     duration = pulseIn(rec, HIGH);
    distance = duration * 0.0344 / 2; // Expression to calculate
                                 // distance using time

    Serial.print("Distance: ");
    Serial.print(
        distance); // Print the output in serial monitor
    Serial.println(" cm");
  if(distance<20) {
    stop();
    delay(1000);
    backward();
    delay(2000);
    right();
    delay(1000);
  }
  else forward();
}

void forward () {
  digitalWrite(n1, HIGH);
  digitalWrite(n2, LOW);
  digitalWrite(n3, HIGH);
  digitalWrite(n4, LOW);
}

void backward () {
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

 void right () {
  digitalWrite(n1, LOW);
  digitalWrite(n2, HIGH);
  digitalWrite(n3, HIGH);
  digitalWrite(n4, LOW);
}

void stop () {
  digitalWrite(n1, LOW);
  digitalWrite(n2, LOW);
  digitalWrite(n3, LOW);
  digitalWrite(n4, LOW);
}
