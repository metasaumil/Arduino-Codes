#include <Wire.h>

#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo doorServo;

// Buzzer pin
#define BUZZER_PIN 11
#define GREEN 12
#define RED 13

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {2, 3, 4, 5};     // Connect to R1-R4
byte colPins[COLS] = {6, 7, 8, 10};    // Connect to C1-C4

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String password = "1234";
String input = "";

void setup() {
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  lcd.init();
  lcd.backlight();
  pinMode(BUZZER_PIN, OUTPUT);
  doorServo.attach(9); // Connect servo signal to pin 9
  doorServo.write(0);  // Locked position
  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    beepShort();
    if (key == '#') {
      lcd.clear();
      if (input == password) {
        digitalWrite(GREEN, HIGH);
        lcd.print("Access Granted");
        beepSuccess();
        doorServo.write(90); // Unlock
        delay(3000);
        doorServo.write(0);  // Lock again
        digitalWrite(GREEN, LOW);
      } else {
        lcd.print("Access Denied");
        beepError();
      }
      input = "";
      delay(2000);
      lcd.clear();
      lcd.print("Enter Password:");
    } else if (key == '*') {
      input = "";
      lcd.setCursor(0, 1);
      lcd.print("                ");
    } else if (input.length() < 16) {
          input += key;
          lcd.setCursor(0, 1);
          for (int i = 0; i < input.length(); i++) {
            lcd.print("*");
          }
    }
  }
}

// 🔊 Buzzer functions
void beepShort() {
  tone(BUZZER_PIN, 1000, 100);
}

void beepSuccess() {
  tone(BUZZER_PIN, 1500, 200);
  delay(250);
  tone(BUZZER_PIN, 2000, 200);
  delay(250);
  noTone(BUZZER_PIN);
}

void beepError() {
  for(int i = 0; i<3; i++) {
    digitalWrite(RED, HIGH);
    tone(BUZZER_PIN, 500, 400);
    delay(400);
    digitalWrite(RED, LOW);
    noTone(BUZZER_PIN);
    delay(100);
  }
}
