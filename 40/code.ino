#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <EEPROM.h>
#define DHTPIN 4
#define DHTTYPE DHT22
#define ldrPin A0
#define ledPin 7
#define buzzerPin 8
DHT dht(DHTPIN, DHTTYPE);
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
String input = "";
String storedPassword = "";
bool loggedIn = false;

void setup() {
  lcd.init();
  lcd.backlight();
  dht.begin();
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  for (int i = 0; i < 4; i++) {
    char c = EEPROM.read(i);
    if (c >= '0' && c <= '9') storedPassword += c;
  }

  if (storedPassword.length() != 4) {
    storedPassword = "1234";
    for (int i = 0; i < 4; i++) EEPROM.write(i, storedPassword[i]);
  }
  lcd.print("Enter Password");
}

void loop() {

  char key = keypad.getKey();

  if (!loggedIn) {
    if (key) {
      if (key == '#') {
        if (input == storedPassword) {
          loggedIn = true;
          lcd.clear();
          lcd.print("Access Granted");
          delay(1000);
        } 
        else {
          lcd.clear();
          lcd.print("Wrong Password");
          tone(buzzerPin, 2000);
          delay(500);
          noTone(buzzerPin);
          delay(1000);
        }
        input = "";
        lcd.clear();
      }
      else {
        input += key;
        lcd.setCursor(0,1);
        lcd.print("****");
      }
    }
    return;
  }

  float temp = dht.readTemperature();
  int ldr = analogRead(ldrPin);
  lcd.setCursor(0,0);
  lcd.print("T:");
  lcd.print(temp);
  lcd.setCursor(0,1);
  lcd.print("L:");
  lcd.print(ldr);
  digitalWrite(ledPin, ldr < 500);

  if (temp > 32) {
    tone(buzzerPin, 2000);
  } 
  else {
    noTone(buzzerPin);
  }
  delay(1000);
}
