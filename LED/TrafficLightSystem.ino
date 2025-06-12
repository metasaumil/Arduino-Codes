    const int redLED = 13;
const int yellowLED = 12;
const int greenLED = 11;

const int irSensor = 7;
const int buzzer = 6;

bool isGreen = false;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  
  pinMode(irSensor, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // RED phase
  isGreen = false;
  digitalWrite(redLED, HIGH);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);
  checkVehicle(5000);

  // RED + YELLOW phase (get ready)
  digitalWrite(redLED, HIGH);
  digitalWrite(yellowLED, HIGH);
  digitalWrite(greenLED, LOW);
  checkVehicle(2000);

  // GREEN phase
  isGreen = true;
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, HIGH);
  checkVehicle(5000);

  // YELLOW phase (prepare to stop)
  isGreen = false;
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, HIGH);
  digitalWrite(greenLED, LOW);
  checkVehicle(2000);
}

void checkVehicle(int duration) {
  int elapsed = 0;
  while (elapsed < duration) {
    if (!isGreen && digitalRead(irSensor) == LOW) {
      // Vehicle detected when light is not green
      digitalWrite(buzzer, HIGH);
    } else {
      digitalWrite(buzzer, LOW);
    }
    delay(100);
    elapsed += 100;
  }
}
