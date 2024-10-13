int input_ldr = A0, output_relay = 10, ldr_state = 0, last_ldr_state = 0;

void setup() {
  // put your setup code here, to run once:
  //pinMode(A0, INPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  //intensity = analogRead(input_ldr);
  ldr_state = analogRead(input_ldr);
  if(ldr_state == last_ldr_state)
    if(ldr_state > 500) 
      //if(intensity<500&&intensity>200)
      digitalWrite(output_relay,LOW);
    else 
      digitalWrite(output_relay,HIGH);
    
  last_ldr_state = ldr_state;
}
