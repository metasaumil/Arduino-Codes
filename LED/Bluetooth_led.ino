char command;
int ledstate = 0;

void setup() {
  pinMode(13, OUTPUT); // Set the LED pin as an output
  Serial.begin(9600); // Start serial communication with the Bluetooth module
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();
    Serial.println(command);
    if(command == '1') {
      ledstate++;
      if(ledstate%2!=0)
        digitalWrite(13, HIGH);
      else
        digitalWrite(13, LOW);
    }
  }
}
