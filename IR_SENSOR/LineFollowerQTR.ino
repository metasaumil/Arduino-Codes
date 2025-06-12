const int sensorPins[8] = {2, 3, 4, 7, 8, 9, 12, 13}; 
int sensorValues[8];
int IN1 = 5, IN2 = 6;
int IN3 = 10, IN4 = 11;
int speed = 255;

void setup() {
  Serial.begin(9600);
  Serial.println("Initialising");
  for (int i = 0; i < 8; i++)
    pinMode(sensorPins[i], INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  for (int i = 0; i < 8; i++)
    sensorValues[i] = digitalRead(sensorPins[i]);

  for (int i = 0; i < 8; i++) {
    Serial.print(sensorValues[i]);
    Serial.print(" ");
  }
  Serial.println();

  int flag = 1;
  for(int i = 0; i<8; i++)
    if(sensorValues[i]==1)
      flag = 0;
  if(flag)
    stop();
  else if (sensorValues[3] == 0 || sensorValues[4] == 0)
    forward();
  else if (sensorValues[0] == 0 || sensorValues[1] == 0 || sensorValues[2] == 0)
    right();
  else if (sensorValues[5] == 0 || sensorValues[6] == 0 || sensorValues[7] == 0)
    left();
  else
    backward();
  delay(50);
}

// Motor movement functions

void forward() {
  Serial.println("Forward");
  analogWrite(IN1, speed);
  analogWrite(IN2, 0);
  analogWrite(IN3, speed);
  analogWrite(IN4, 0);
}

void backward() {
  Serial.println("Backward");
  analogWrite(IN1, 0);
  analogWrite(IN2, speed);
  analogWrite(IN3, 0);
  analogWrite(IN4, speed);
}

void left() {
  Serial.println("Left");
  analogWrite(IN1, 0);
  analogWrite(IN2, speed);
  analogWrite(IN3, speed);
  analogWrite(IN4, 0);
}

void right() {
  Serial.println("Right");
  analogWrite(IN1, speed);
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  analogWrite(IN4, speed);
}

void stop() {
  Serial.println("Stop");
  analogWrite(IN1, 0);
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  analogWrite(IN4, 0);
}