#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
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
  lcd.init();
  lcd.backlight();
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  for (int i = 0; i < 4; i++) {
    char c = EEPROM.read(i);
    if (c >= '0' && c <= '9') storedPassword += c;
  }

  if (storedPassword.length() != 4) {
    storedPassword = "1234";
    for (int i = 0; i < 4; i++) {
      EEPROM.write(i, storedPassword[i]);
    }
  }

  lcd.setCursor(0,0);
  lcd.print("Enter Password");
}

void loop() {
  char key = keypad.getKey();
  if (key) {
    if (key == '#') {
      lcd.clear();
      if (input == storedPassword) {
        lcd.print("Access Granted");
        digitalWrite(ledPin, HIGH);
      } 
      else {
        lcd.print("Wrong Password");
        tone(buzzerPin, 2000);
        delay(500);
        noTone(buzzerPin);
      }
      delay(1500);
      input = "";
      lcd.clear();
      lcd.print("Enter Password");
    }
    else if (key == '*') {
      input = "";
      lcd.clear();
      lcd.print("Cleared");
      delay(800);
      lcd.clear();
      lcd.print("Enter Password");
    }

    else if (key == 'A') {
      if (input.length() == 4) {
        for (int i = 0; i < 4; i++) {
          EEPROM.write(i, input[i]);
        }
        storedPassword = input;
        lcd.clear();
        lcd.print("Pass Updated");
        delay(1000);
      }
      input = "";
      lcd.clear();
      lcd.print("Enter Password");
    }
    else {
      input += key;

      lcd.setCursor(0,1);
      lcd.print("****"); 
    }
  }
}
