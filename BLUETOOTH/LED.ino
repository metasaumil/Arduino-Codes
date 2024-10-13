char receivedChar;

void setup() {
  pinMode(13, OUTPUT); // Set the LED pin as an output
  Serial.begin(9600); // Start serial communication with the Bluetooth module
}

void loop() {
  if (Serial.available() > 0) {
    receivedChar = Serial.read();
    if (receivedChar == '1') {
      digitalWrite(ledPin, HIGH);
      Serial.println("LED ON");
    } else if (receivedChar == '0') {
      digitalWrite(ledPin, LOW);
      Serial.println("LED OFF");
    }
  }
}
