int buttonPin = 7, ledPin =  13;
int buttonState = 0, lastButtonState = 0, ledState = LOW;            

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) 
      ledState = !ledState;
    delay(50);
  }
  lastButtonState = buttonState;
  digitalWrite(ledPin, ledState);
}
