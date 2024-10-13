int a = 13, b = 12, c = 11, d = 10, e = 9, f = 8, g = 7, count = 0, button = 6;

void setup() {
for(int i = 7; i<=13; i++)
  pinMode(i, OUTPUT);
pinMode(button, INPUT);
}

void loop() {
  if(digitalRead(button)==HIGH)
    count++;
  switch(count) {
  case 0://0
  clear();
  for(int i = 8; i<=13; i++)
  digitalWrite(i, HIGH);
  break;
  case 1://1
  clear();
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  break;
  case 2://2
  clear();
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(g, HIGH);
  break;
  case 3://3
  clear();
  for(int i = 13; i>=10; i--)
    digitalWrite(i, HIGH);
  digitalWrite(g, HIGH);
  break;
  case 4://4
  clear();
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  break;
  case 5://5
  clear();
  digitalWrite(a, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  break;
  case 6://6
  clear();
  for(int i = 7; i<=13; i++)
    if(i!=12)
      digitalWrite(i, HIGH);
  break;
  case 7://7
  clear();
  for(int i = 11; i<=13; i++)
    digitalWrite(i, HIGH);
  break;
  case 8://8
  clear();
  for(int i = 7; i<=13; i++)
    digitalWrite(i, HIGH);
  break;
  case 9://9
  clear();
  for(int i = 7; i<=13; i++)
    if(i!=9)
      digitalWrite(i, HIGH);
  break;
}
delay(500);
}

void clear() {
  for(int j = 7; j<=13; j++)
    digitalWrite(j, LOW);
}
