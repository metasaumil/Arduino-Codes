void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(2) == 1)  {
   digitalWrite(13, 1);
   Serial.println("Motion detected!");
   //delay(1000);
  }
  else {
   digitalWrite(13, 0);
   Serial.println("No motion!");
  }
}
