#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // (address, columns, rows)

unsigned long previousMillis = 0;
int seconds = 0;
int minutes = 0;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Stopwatch Ready!");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Time: 00:00");
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= 1000) {
    previousMillis = currentMillis;
    seconds++;

    if (seconds >= 60) {
      seconds = 0;
      minutes++;
    }

    char timeBuffer[6];
    sprintf(timeBuffer, "%02d:%02d", minutes, seconds);

    lcd.setCursor(6, 0);
    lcd.print(timeBuffer);
  }
}
