int l1 = 13;
int l2 = 12;

void setup() {
  // put your setup code here, to run once:
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(l1, HIGH);
  digitalWrite(l2, LOW);
  delay(100);
  digitalWrite(l1, LOW);
  digitalWrite(l2, HIGH);
  delay(100);
}
