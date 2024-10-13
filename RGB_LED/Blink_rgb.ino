// Define the pin numbers for the RGB LED
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

// Function to set the color of the RGB LED (for common anode)
void setColor(int red, int green, int blue) {
  analogWrite(redPin, 255 - red);
  analogWrite(greenPin, 255 - green);
  analogWrite(bluePin, 255 - blue);
}

void setup() {
  // Set the RGB pins as outputs
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // Start with the LED off
  setColor(0, 0, 0);
}

void loop() {
  // Set the LED to red for 3 seconds
  setColor(255, 0, 0);  // Full red, no green, no blue
  delay(1000);  // Wait for 3 seconds

  // Set the LED to green for 3 seconds
  setColor(0, 255, 0);  // No red, full green, no blue
  delay(1000);  // Wait for 3 seconds

  // Set the LED to blue for 3 seconds
  setColor(0, 0, 255);  // No red, no green, full blue
  delay(1000);  // Wait for 3 seconds

  // Turn off the LED for 3 seconds
  setColor(0, 0, 0);  // No red, no green, no blue
  delay(1000);  // Wait for 3 seconds
}