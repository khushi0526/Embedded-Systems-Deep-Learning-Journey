#include <LiquidCrystal_I2C.h>
#define ldrPin A0
#define ledPin 7
#define buttonPin 6
LiquidCrystal_I2C lcd(0x27, 16, 2);
int screen = 0;
bool lastButton = HIGH;
bool mode = 0;          // 0 = AUTO, 1 = MANUAL
bool ledState = LOW;

unsigned long pressTime = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  lcd.init();
  lcd.backlight();
}

void loop() {

  int ldr = analogRead(ldrPin);
  bool button = digitalRead(buttonPin);

  // Button press detected
  if (lastButton == HIGH && button == LOW) {
    pressTime = millis();
  }

  // Button release detected
  if (lastButton == LOW && button == HIGH) {
    unsigned long duration = millis() - pressTime;

    if (duration > 800) {
      // LONG PRESS → toggle mode
      mode = !mode;
    } else {
      // SHORT PRESS → change screen
      screen++;
      if (screen > 3) screen = 0;
    }
  }

  lastButton = button;

  // AUTO Mode
  if (mode == 0) {
    ledState = (ldr < 500);
  } 
  // MANUAL Mode (press button while on screen 1 to toggle LED)
  else {
    if (screen == 1 && lastButton == HIGH && button == LOW) {
      ledState = !ledState;
      delay(200);
    }
  }

  digitalWrite(ledPin, ledState);

  // LCD update (no full clear to reduce flicker)
  lcd.setCursor(0, 0);

  switch (screen) {

    case 0:
      lcd.print("Light Value:   ");
      lcd.setCursor(0, 1);
      lcd.print(ldr);
      lcd.print("     ");
      break;

    case 1:
      lcd.print("LED Status:    ");
      lcd.setCursor(0, 1);
      lcd.print(ledState ? "ON " : "OFF");
      lcd.print("        ");
      break;

    case 2:
      lcd.print("Mode:          ");
      lcd.setCursor(0, 1);
      lcd.print(mode ? "MANUAL " : "AUTO   ");
      break;

    case 3:
      lcd.print("Short: Screen  ");
      lcd.setCursor(0, 1);
      lcd.print("Long: Mode     ");
      break;
  }

  delay(100);
}
