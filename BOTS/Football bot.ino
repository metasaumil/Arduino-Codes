#include <Wire.h>

#include <SoftwareSerial.h>
#include <Servo.h>
// Define tne Bluetooth module pins
#define BT_RX_PIN 10
#define BT_TX_PIN 11
// Create a SoftwareSerial object tor Bluetooth connunication
SoftwareSerial BTSerial(BT_RX_PIN, BT_TX_PIN);
//Define motor pins
int motor1Pin1= 2;
int motor1Pin2= 3;
int motor2Pin1 = 4;
int motor2Pin2=5;
//Define servo pin
int servoPin = 6;
// Create a Servo ohjact for the kicking sorvo
Servo kickingServo;

void setup() 
{
// Set motor pins as output
pinMode(motor1Pin1, OUTPUT);
pinMode(motor1Pin2, OUTPUT);
pinMode(motor2Pin1, OUTPUT);
pinMode(motor2Pin2, OUTPUT);
// Attach the kicking servo to the servo pin
kickingServo.attach(servoPin);
// Initialize serial communication with a baud rate of 9600
Serial.begin(9600);
//Initialize Bluetooth serial comnunication with a baud rate of 9600
BTSerial.begin(9600);
}

void loop()
{
  //check if there is data available to read from Bluetooth 
  if(BTSerial.available())
  {
    char command = BTSerial.read();
    // control the robot based on receiving commands
    if(command == 'F'){
      moveForward();      
     } else if (command== 'B'){
        moveBackward();
      } else if (command == 'L'){
       turnleft();
       } else if (command == 'R'){
         turnRight();
        } else if (command== 'W'){
          kick();
         }
         else if(command == 'w') {
           kick();
         }else if (command =='S'){
        stopMoving();
        }
  }
}


// Function to move the robot forward
void moveForward() {
digitalWrite(motor1Pin1, LOW);
digitalWrite(motor1Pin2, HIGH);
digitalWrite(motor2Pin1, HIGH);
digitalWrite(motor2Pin2, LOW);

}
// Function to move the robot backward
void moveBackward() {
digitalWrite(motor1Pin1, HIGH);
digitalWrite(motor1Pin2, LOW);
digitalWrite(motor2Pin1, LOW);
digitalWrite(motor2Pin2, HIGH);

}


// Function to turn the robot left
void turnleft() {
digitalWrite(motor1Pin1, LOW);
digitalWrite(motor1Pin2, HIGH);
digitalWrite(motor2Pin1, LOW);
digitalWrite(motor2Pin2, HIGH);

}
// Function to turn the robot right
void turnRight() {
digitalWrite(motor1Pin1, HIGH);
digitalWrite(motor1Pin2, LOW);
digitalWrite(motor2Pin1, HIGH);
digitalWrite(motor2Pin2, LOW);

}


// Function to stop the robot
void stopMoving() {
digitalWrite(motor1Pin1, LOW);
digitalWrite(motor1Pin2, LOW);
digitalWrite(motor2Pin1, LOW);
digitalWrite(motor2Pin2, LOW);

}
// Function to kick the ball
void kick() {
kickingServo.write(90); // Set the kicking servo to 90 degrees
delay(100); // Wait for 1 second
kickingServo.write(0); // Set the kicking servo back to 0 degrees
}