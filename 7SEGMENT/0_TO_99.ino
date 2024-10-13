int a = 13, b = 12, c = 11, d = 10, e = 9, f = 8, g = 7, a2 = 6, b2 = 5, c2 = 4, d2 = 3, e2 = 2, f2 = 1, g2 = 0, count = 0;

void setup() {
  for(int i = 0; i<=13; i++)
    pinMode(i, OUTPUT);
}

void loop() {
  int ten = count/10, one = count%10;
  displayNum(ten, 0);
  displayNum(one, 7);
  count++;
  if(count>99) count = 0;
  delay(500);
}

void displayNum(int n, int x) {
  switch(n) {
  case 0://0
  clear(x);
  for(int i = 8-x; i<=13-x; i++)
  digitalWrite(i, HIGH);
  break;
  case 1://1
  clear(x);
  digitalWrite(b-x, HIGH);
  digitalWrite(c-x, HIGH);
  break;
  case 2://2
  clear(x);
  digitalWrite(a-x, HIGH);
  digitalWrite(b-x, HIGH);
  digitalWrite(d-x, HIGH);
  digitalWrite(e-x, HIGH);
  digitalWrite(g-x, HIGH);
  break;
  case 3://3
  clear(x);
  for(int i = 13-x; i>=10-x; i--)
    digitalWrite(i, HIGH);
  digitalWrite(g-x, HIGH);
  break;
  case 4://4
  clear(x);
  digitalWrite(b-x, HIGH);
  digitalWrite(c-x, HIGH);
  digitalWrite(f-x, HIGH);
  digitalWrite(g-x, HIGH);
  break;
  case 5://5
  clear(x);
  digitalWrite(a-x, HIGH);
  digitalWrite(f-x, HIGH);
  digitalWrite(g-x, HIGH);
  digitalWrite(c-x, HIGH);
  digitalWrite(d-x, HIGH);
  break;
  case 6://6
  clear(x);
  for(int i = 7-x; i<=13-x; i++)
    if(i!=12-x)
      digitalWrite(i, HIGH);
  break;
  case 7://7
  clear(x);
  for(int i = 11; i<=13; i++)
    digitalWrite(i-x, HIGH);
  break;
  case 8://8
  clear(x);
  for(int i = 7; i<=13; i++)
    digitalWrite(i-x, HIGH);
  break;
  case 9://9
  clear(x);
  for(int i = 13-x; i>=7-x; i--)
    if(i!=9-x)
      digitalWrite(i, HIGH);
  break;
}
}

void clear(int x) {
  for(int j = 7-x; j<=13-x; j++)
    digitalWrite(j, LOW);
}
