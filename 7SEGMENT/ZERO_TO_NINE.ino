int a = 13, b = 12, c = 11, d = 10, e = 9, f = 8, g = 7;

void setup() {
for(int i = 7; i<=13; i++)
  pinMode(i, OUTPUT);
}

void loop() {
  //0
  for(int i = 8; i<=13; i++)
  digitalWrite(i, HIGH);
  clear();
  //1
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  clear();
  //2
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(g, HIGH);
  clear();
  //3
  for(int i = 13; i>=10; i--)
    digitalWrite(i, HIGH);
  digitalWrite(g, HIGH);
  clear();
  //4
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  clear();
  //5
  digitalWrite(a, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  clear();
  //6
  for(int i = 7; i<=13; i++)
    if(i!=12)
      digitalWrite(i, HIGH);
  clear();
  //7
  for(int i = 11; i<=13; i++)
    digitalWrite(i, HIGH);
  clear();
  //8
  for(int i = 7; i<=13; i++)
    digitalWrite(i, HIGH);
  clear();
  //9
  for(int i = 7; i<=13; i++)
    if(i!=9)
      digitalWrite(i, HIGH);
  clear();
}

void clear() {
  delay(1000);
  for(int j = 7; j<=13; j++)
    digitalWrite(j, LOW);
}