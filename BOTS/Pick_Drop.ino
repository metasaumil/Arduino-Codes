int n1 = 2, n2 = 3, n3 = 4, n4 = 5, m1 = 6, m2 = 7, m3 = 8, m4 = 9;
char command;
void setup() 
{
  pinMode(n1, OUTPUT);
  pinMode(n2, OUTPUT);
  pinMode(n3, OUTPUT);
  pinMode(n4, OUTPUT);
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
  Serial.begin(9600); 
}
void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();
    Serial.println(command);
    if(command == 'F')
      backward();      
    else if (command== 'B')
      forward();
    else if (command == 'L')
      left();
    else if (command == 'R')
      right();
    else if (command =='0') {
      stop();
      stop_gripper();
      stop_hand();
    }
    else if(command == 'T')
      open();
    else if(command == 'X')
      close();
    else if(command == 'S')
        up();
    else if(command == 'C')
      down();
  }
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
void open() {
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
}
void close() {
  digitalWrite(m1, LOW);
  digitalWrite(m2, HIGH);
}
void up() {
  digitalWrite(m3, HIGH);
  digitalWrite(m4, LOW);
}
void down() {
  digitalWrite(m3, LOW);
  digitalWrite(m4, HIGH);
}
void stop_gripper() {
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
}
void stop_hand() {
  digitalWrite(m3, LOW);
  digitalWrite(m4, LOW);
}