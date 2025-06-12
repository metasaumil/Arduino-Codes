#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pins
#define btnJump 2
#define btnFire 3
#define buzzerPin 9

// Game state
int playerRow = 0;
bool playerBulletActive = false;
int playerBulletCol, playerBulletRow;

bool obstacleActive = true;
int obstacleCol = 15;
int obstacleRow = 0;

bool obstacleBulletActive = false;
int obstacleBulletCol, obstacleBulletRow;

unsigned long lastObstacleMove = 0;
unsigned long lastPlayerBulletMove = 0;
unsigned long lastObstacleBulletMove = 0;

int score = 0;
int obstacleSpeed = 180;
int playerBulletSpeed = 50;
int obstacleBulletSpeed = 130;

bool gameOverState = false;

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(btnJump, INPUT_PULLUP);
  pinMode(btnFire, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
  welcomeScreen();
}

void loop() {
  if (gameOverState) {
    if (digitalRead(btnJump) == LOW || digitalRead(btnFire) == LOW) {
      delay(200);
      resetGame();
    }
    return;
  }

  // Jump button
9  if (digitalRead(btnJump) == LOW) {
    playerRow = 1 - playerRow;
    delay(200);
  }

  // Fire button
  if (digitalRead(btnFire) == LOW && !playerBulletActive) {
    playerBulletActive = true;
    playerBulletCol = 3;
    playerBulletRow = playerRow;
    tone(buzzerPin, 1000, 100);
    delay(200);
  }

  unsigned long now = millis();

  // Bullet hits obstacle
  if (playerBulletActive && playerBulletCol >= obstacleCol && playerBulletRow == obstacleRow && obstacleActive) {
    playerBulletActive = false;
    obstacleActive = false;
    score++;
    tone(buzzerPin, 1500, 80);
    obstacleCol = 15;
    obstacleRow = random(0, 2);
    obstacleActive = true;
  }

  // Obstacle hits player
  if (obstacleCol == 2 && obstacleRow == playerRow && obstacleActive) {
    showGameOver();
    return;
  }

  // Obstacle bullet hits player
  if (obstacleBulletActive && obstacleBulletCol == 2 && obstacleBulletRow == playerRow) {
    showGameOver();
    return;
  }

  // Obstacle movement
  if (now - lastObstacleMove > obstacleSpeed) {
    obstacleCol--;
    if (obstacleCol < 0) {
      obstacleCol = 15;
      obstacleRow = random(0, 2);
    }
    lastObstacleMove = now;

    if (!obstacleBulletActive && random(0, 100) < 30) {
      obstacleBulletActive = true;
      obstacleBulletCol = obstacleCol - 1;
      obstacleBulletRow = obstacleRow;
    }
  }

  // Player bullet movement
  if (playerBulletActive && now - lastPlayerBulletMove > playerBulletSpeed) {
    playerBulletCol++;
    if (playerBulletCol > 15) playerBulletActive = false;
    lastPlayerBulletMove = now;
  }

  // Obstacle bullet movement
  if (obstacleBulletActive && now - lastObstacleBulletMove > obstacleBulletSpeed) {
    obstacleBulletCol--;
    if (obstacleBulletCol < 0) obstacleBulletActive = false;
    lastObstacleBulletMove = now;
  }

  // Render
  lcd.clear();
  lcd.setCursor(2, playerRow); lcd.print("O");
  if (playerBulletActive) lcd.setCursor(playerBulletCol, playerBulletRow), lcd.print(".");
  if (obstacleActive) lcd.setCursor(obstacleCol, obstacleRow), lcd.print("X");
  if (obstacleBulletActive) lcd.setCursor(obstacleBulletCol, obstacleBulletRow), lcd.print("*");

  delay(30);
}

void showGameOver() {
  gameOverState = true;
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("GAME OVER!");
  lcd.setCursor(4, 1);
  lcd.print("Score: ");
  lcd.print(score);

  for (int i = 0; i < 3; i++) {
    tone(buzzerPin, 400, 200);
    delay(300);
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Press any btn");
  lcd.setCursor(0, 1);
  lcd.print("to restart");
}

void resetGame() {
  playerRow = 0;
  playerBulletActive = false;
  obstacleActive = true;
  obstacleCol = 15;
  obstacleRow = random(0, 2);
  obstacleBulletActive = false;
  score = 0;
  gameOverState = false;
  lcd.clear();
}

void welcomeScreen() {
  lcd.setCursor(0, 0);
  lcd.print("  ROBOTICS ERA  ");
  lcd.setCursor(0, 1);
  lcd.print("  SHOOTER GAME  ");
  delay(1500);
  lcd.clear();
}
