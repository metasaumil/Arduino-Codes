#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int MODE_BUTTON = 2;
const int START_BUTTON = 3;
const int BUZZER_PIN = 5;

enum Mode { STOPWATCH, TIMER };
Mode currentMode = STOPWATCH;

bool running = false;
unsigned long lastUpdate = 0;
unsigned long elapsed = 0;
int timerSeconds = 0;
bool timerEnded = false;

void setup() {
  pinMode(MODE_BUTTON, INPUT_PULLUP);
  pinMode(START_BUTTON, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Mode: Stopwatch");
  delay(1500);
  lcd.clear();
}

void loop() {
  handleButtons();

  if (running && millis() - lastUpdate >= 1000) {
    lastUpdate = millis();

    if (currentMode == STOPWATCH) {
      elapsed++;
    } else if (currentMode == TIMER && timerSeconds > 0) {
      timerSeconds--;
      if (timerSeconds == 0) {
        timerEnded = true;
        running = false;
      }
    }
  }

  if (timerEnded) {
    playTickTick();
  }

  updateDisplay();
}

void handleButtons() {
  static bool lastModeState = HIGH;
  static bool lastStartState = HIGH;

  bool modeState = digitalRead(MODE_BUTTON);
  bool startState = digitalRead(START_BUTTON);

  if (lastModeState == HIGH && modeState == LOW) {
    buzzShort();
    currentMode = (currentMode == STOPWATCH) ? TIMER : STOPWATCH;
    running = false;
    elapsed = 0;
    timerSeconds = 0;
    timerEnded = false;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print((currentMode == STOPWATCH) ? "Mode: Stopwatch" : "Mode: Timer");
    delay(1000);
    lcd.clear();
  }

  if (lastStartState == HIGH && startState == LOW) {
    if (currentMode == TIMER && timerSeconds == 0) {
      timerSeconds = 60;
    }
    running = !running;
    timerEnded = false;
    lastUpdate = millis();
    buzzShort();
  }

  lastModeState = modeState;
  lastStartState = startState;
}

void updateDisplay() {
  lcd.setCursor(0, 0);
  lcd.print((currentMode == STOPWATCH) ? "Stopwatch" : "Timer    ");

  int totalSeconds = (currentMode == STOPWATCH) ? elapsed : timerSeconds;
  int minutes = totalSeconds / 60;
  int seconds = totalSeconds % 60;

  lcd.setCursor(0, 1);
  char buffer[17];
  sprintf(buffer, "Time: %02d:%02d", minutes, seconds);
  lcd.print(buffer);
}

void buzzShort() {
  digitalWrite(BUZZER_PIN, HIGH);
  delay(80);
  digitalWrite(BUZZER_PIN, LOW);
}

void playTickTick() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(100);
    digitalWrite(BUZZER_PIN, LOW);
    delay(150);
  }
  timerEnded = false;
}
