// Define pin numbers
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;
const int buttonPin = 2;

// Variable to store the current state of the button
int buttonState = 0;
int lastButtonState = 0;

// Variable to store the current color index
int colorIndex = 0;

// Array of colors (each color is an array of three values: red, green, blue)
int colors[][3] = {
  {255, 0, 0},    // Red
  {0, 255, 0},    // Green
  {0, 0, 255},    // Blue
  {255, 255, 0},  // Yellow
  {0, 255, 255},  // Cyan
  {255, 0, 255},  // Magenta
  {255, 255, 255},// White
  {0, 0, 0}       // Off
};

void setup() {
  // Initialize the RGB LED pins as outputs
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // Initialize the button pin as input with internal pull-up resistor enabled
  pinMode(buttonPin, INPUT_PULLUP);

  // Initialize the serial communication (optional for debugging)
  Serial.begin(9600);

  // Set initial color
  setColor(colors[colorIndex]);
}

void loop() {
  // Read the state of the button
  buttonState = digitalRead(buttonPin);

  // Check if the button has been pressed
  if (buttonState == LOW && lastButtonState == HIGH) {
    // Button has been pressed, change to the next color
    colorIndex = (colorIndex + 1) % 8;  // Cycle through the colors
    setColor(colors[colorIndex]);

    // Debug print the current color index
    Serial.println(colorIndex);
  }

  // Save the current button state as the last button state
  lastButtonState = buttonState;

  // Small delay to debounce the button
  delay(50);
}

// Function to set the color of the RGB LED
void setColor(int color[3]) {
  analogWrite(redPin, color[0]);
  analogWrite(greenPin, color[1]);
  analogWrite(bluePin, color[2]);
}