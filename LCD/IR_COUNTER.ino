#include<LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int ir = 13, count = 0;

void setup() {
 lcd.begin(16, 2); 
pinMode(ir, INPUT);
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print(count);
  Serial.println(count);
  if(digitalRead(ir)==0) {
    count++;
    delay(1000); // Delay a little bit to improve simulation performance
  }     
}