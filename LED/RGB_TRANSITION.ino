// Define the pin numbers for the RGB LED
const int redPin = 9;    // PWM pin for the red LED
const int greenPin = 10; // PWM pin for the green LED
const int bluePin = 11;  // PWM pin for the blue LED

// Define an array of colors (R, G, B values)
const int colors[][3] = {
  {255, 0, 0},    // Red
  {0, 255, 0},    // Green
  {0, 0, 255},    // Blue
  {255, 255, 0},  // Yellow
  {0, 255, 255},  // Cyan
  {255, 0, 255},  // Magenta
  {255, 255, 255},// White
  {128, 0, 0},    // Dark Red
  {0, 128, 0},    // Dark Green
  {0, 0, 128},    // Dark Blue
  {128, 128, 0},  // Olive
  {0, 128, 128},  // Teal
  {128, 0, 128}   // Purple
};

const int numColors = sizeof(colors) / sizeof(colors[0]);

// Time to display each color (in milliseconds)
const int transitionTime = 2000; // Time to transition between colors
const int steps = 100; // Number of steps in the transition

void setup() {
  // Set the RGB LED pins as outputs
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // Cycle through each color in the array
  for (int i = 0; i < numColors; i++) {
    int nextColorIndex = (i + 1) % numColors;
    smoothTransition(colors[i], colors[nextColorIndex]);
  }
}

// Function to set the color of the RGB LED
void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

// Function to smoothly transition between two colors
void smoothTransition(const int startColor[3], const int endColor[3]) {
  while(Serial.available()>0) {
    int step = Serial.read();
    Serial.print("Transition completed :");
    Serial.println(step);
    float progress = (float) step / steps;
    int red = startColor[0] + progress * (endColor[0] - startColor[0]);
    int green = startColor[1] + progress * (endColor[1] - startColor[1]);
    int blue = startColor[2] + progress * (endColor[2] - startColor[2]);

    setColor(red, green, blue);
    delay(transitionTime / steps);
  }
}