#include <DHT.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 4
#define DHTTYPE DHT22
#define ldrPin A0
#define ledPin 7
#define buzzerPin 8
#define buttonPin 6

DHT dht(DHTPIN, DHTTYPE);
Servo vent;
LiquidCrystal_I2C lcd(0x27, 16, 2);

int screen = 0;
bool mode = 0;
bool lastButton = HIGH;
bool ledState = 0;
bool ventState = 0;

unsigned long lastUpdate = 0;

void setup() {
  Serial.begin(9600);
  dht.begin();
  vent.attach(9);

  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  lcd.init();
  lcd.backlight();
}

void loop() {
  bool button = digitalRead(buttonPin);

  // Screen change
  if (lastButton == HIGH && button == LOW) {
    screen++;
    if (screen > 4) screen = 0;

    if (screen == 4) {
      mode = !mode;
    }
    delay(300);
  }
  lastButton = button;

  int ldr = analogRead(ldrPin);
  float temp = dht.readTemperature();
  if (isnan(temp)) return;

  // AUTO MODE
  if (mode == 0) {
    digitalWrite(ledPin, ldr < 500);

    if (temp < 28) {
      vent.write(0);
      noTone(buzzerPin);
    }
    else if (temp <= 32) {
      vent.write(90);
    }
    else {
      vent.write(180);
      tone(buzzerPin, 2000);
      delay(150);
      noTone(buzzerPin);
      delay(200);
    }
  }

  // MANUAL MODE
  else {
    if (button == LOW) {
      ledState = !ledState;
      ventState = !ventState;

      digitalWrite(ledPin, ledState);
      vent.write(ventState ? 90 : 0);

      delay(300);
    }
    noTone(buzzerPin);
  }

  // LCD UPDATE
  if (millis() - lastUpdate > 1000) {
    lastUpdate = millis();
    lcd.clear();

    switch (screen) {
      case 0:
        lcd.setCursor(0, 0);
        lcd.print("Temp:");
        lcd.setCursor(0, 1);
        lcd.print(temp);
        break;

      case 1:
        lcd.setCursor(0, 0);
        lcd.print("Light:");
        lcd.setCursor(0, 1);
        lcd.print(ldr < 500 ? "ON" : "OFF");
        break;

      case 2:
        lcd.setCursor(0, 0);
        lcd.print("Vent:");
        lcd.setCursor(0, 1);
        if (temp < 28) lcd.print("Closed");
        else if (temp <= 32) lcd.print("Half");
        else lcd.print("Open");
        break;

      case 3:
        lcd.setCursor(0, 0);
        lcd.print("Mode:");
        lcd.setCursor(0, 1);
        lcd.print(mode ? "Manual" : "Auto");
        break;

      case 4:
        lcd.setCursor(0, 0);
        lcd.print("Press->Switch");
        lcd.setCursor(0, 1);
        lcd.print("Mode");
        break;
    }
  }
}
