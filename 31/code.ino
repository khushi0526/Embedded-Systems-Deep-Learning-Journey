#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

#define ledPin 10
#define buzzerPin 11

String password = "1234";
String input = "";

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  char key = keypad.getKey();

  if (key) {
    Serial.print("Key: ");
    Serial.println(key);

    if (key == '#') {
    
      if (input == password) {
        digitalWrite(ledPin, HIGH);
        Serial.println("Access Granted");
      } else {
        tone(buzzerPin, 2000);
        delay(500);
        noTone(buzzerPin);
        Serial.println("Access Denied");
      }
      input = "";
    }

    else if (key == '*') {
      input = "";
    }

    else {
      input += key;
    }
  }
}
