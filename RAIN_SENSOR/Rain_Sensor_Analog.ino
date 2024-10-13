void setup() {
  Serial.begin(9600);   //enable serial monitor
  pinMode(13, OUTPUT);    //define LED pin
}
void loop() {
  int value = analogRead(A0);     //read value
  Serial.print("Value : ");
  Serial.println(value);
  if (value < 500) {           //check condition
    digitalWrite(13, HIGH);
    delay (2000);
    Serial.print("Heavy rain  LED on ");
  } else {
    digitalWrite(13, LOW);
  }
}
