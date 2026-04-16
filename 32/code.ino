#include <Keypad.h>
#include <EEPROM.h>
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
String input = "";
String storedPassword = "";

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  // Read password from EEPROM
  for (int i = 0; i < 4; i++) {
    storedPassword += char(EEPROM.read(i));
  }

  // If EEPROM empty, set default
  if (storedPassword == "\xFF\xFF\xFF\xFF") {
    storedPassword = "1234";
    for (int i = 0; i < 4; i++) {
      EEPROM.write(i, storedPassword[i]);
    }
  }

  Serial.print("Stored Password: ");
  Serial.println(storedPassword);
}

void loop() {

  char key = keypad.getKey();

  if (key) {
    Serial.println(key);

    if (key == '#') {
      if (input == storedPassword) {
        digitalWrite(ledPin, HIGH);
        Serial.println("Access Granted");
      } else {
        tone(buzzerPin, 2000);
        delay(500);
        noTone(buzzerPin);
        Serial.println("Wrong Password");
      }
      input = "";
    }

    else if (key == '*') {
      input = "";
    }

    else if (key == 'A') {
      // Save new password
      if (input.length() == 4) {
        for (int i = 0; i < 4; i++) {
          EEPROM.write(i, input[i]);
        }
        storedPassword = input;
        Serial.println("Password Updated");
      }
      input = "";
    }

    else {
      input += key;
    }
  }
}
