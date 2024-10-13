void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(2) == 1) 
   Serial.println("Turn on water pump");
  else 
   Serial.println("Turn off water pump");
}
