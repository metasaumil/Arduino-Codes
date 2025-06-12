#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

String str1 = "   WELCOME TO   ";
String str2 = "  ROBOTICS ERA  ";
int i = 0;

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  if(i>15) i = 0;
  lcd.setCursor(0, 0);
  lcd.print(str1.substring(i)+str1.substring(0, i));
  lcd.setCursor(0, 1);
  lcd.print(str2.substring(i)+str2.substring(0, i));
  i++;
  delay(1000);
}

