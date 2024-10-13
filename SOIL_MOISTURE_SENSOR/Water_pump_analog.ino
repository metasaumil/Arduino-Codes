void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
  if(analogRead(A0) > 500) 
   Serial.println("Turn on water pump");
  else 
   Serial.println("Turn off water pump");
}
