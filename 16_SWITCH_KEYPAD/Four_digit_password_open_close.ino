#include <Keypad.h>
#include <Servo.h>

Servo servo;
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the symbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

char password_open[] = "ABCD", password_close[] = "DCBA";
int pass_index = 0;
char current_pass[sizeof(password_open)]; // Use sizeof to ensure the array is large enough
//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup(){
  Serial.begin(9600);
  servo.attach(13);
  servo.write(0);
  Serial.println("Enter password:\nEnter '#' to finish entering password\nEnter '*' to reset entering password");
}
 
void loop(){
  char key = customKeypad.getKey();
 
  if (key){
    if((key >= '0' && key <= '9') || (key >= 'A' && key <= 'D')) {
      current_pass[pass_index] = key;
      pass_index++;
      Serial.print("*");
    }
    if(key == '#') {
      current_pass[pass_index] = '\0';
      if (strcmp(current_pass, password_open) == 0) {
            Serial.println("\nPassword Match! Door opened!");
          servo.write(90);
      }
      else if (strcmp(current_pass, password_close) == 0) {
          Serial.println("\nPassword Match! Door closed!");
          servo.write(0);
      }
      else
        Serial.println("\nIncorrect Password!");
      pass_index = 0;
    }
    if (key == '*') {
      pass_index = 0;
      Serial.println("\nPassword Entry Cleared.");
    }
  }
}
