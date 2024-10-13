//Define motor pins
int n1 = 2, n2 = 3, n3 = 4, n4 = 5;
char command;

void setup() 
{
  // Set motor pins as output
  pinMode(n1, OUTPUT);
  pinMode(n2, OUTPUT);
  pinMode(n3, OUTPUT);
  pinMode(n4, OUTPUT);

  pinMode(13, OUTPUT); // Set the LED pin as an output
  Serial.begin(9600); // Start serial communication with the Bluetooth module
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();
    Serial.println(command);
    if(command == 'F')
      forward();      
    else if (command== 'B')
      backward();
    else if (command == 'L')
      left();
    else if (command == 'R')
      right();
    else if (command =='S')
      stop();    
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