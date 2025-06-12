//if the distance is less than 30cm then the bot takes a step back and turns right

int d = 0;

void setup() {
  Serial.begin(9600);
  for (int i = 2; i <= 5; i++)
    pinMode(i, OUTPUT);
}

void loop() {
  d = readUltrasonicDistance(7, 6) / 58.0;
  Serial.print("Distance: ");
  Serial.print(d);
  Serial.println(" cm");
  
  if (d <= 10 || d >= 20)
    stop();
  else 
    forward();
  delay(100); // Small delay to stabilize reading
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

void backward() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}

void forward() {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
}

void right() {
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}

void left() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
}

void stop() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
}