char receivedChar;

void setup() {
  pinMode(13, OUTPUT); // Set the LED pin as an output
  Serial.begin(9600); // Start serial communication with the Bluetooth module
}

void loop() {
  if (Serial.available() > 0) {
    receivedChar = Serial.read();
    if (receivedChar == 'a') {
      if(digitalRead(13)==HIGH)
        digitalWrite(13, LOW);
      else
      digitalWrite(13, HIGH);
    } else if (receivedChar == 'b') {
      if(digitalRead(12)==HIGH)
        digitalWrite(12, LOW);
      else
      digitalWrite(12, HIGH);
    } else if (receivedChar == 'c') {
      if(digitalRead(11)==HIGH)
        digitalWrite(11, LOW);
      else
      digitalWrite(11, HIGH);
    } else if (receivedChar == 'd') {
      for(int i = 11; i<=13; i++)
        digitalWrite(i, HIGH);
    } else if (receivedChar == 'e') {
      for(int i = 11; i<=13; i++)
        digitalWrite(i, HIGH);
    }
  }
}
