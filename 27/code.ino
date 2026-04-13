#include <DHT.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#define DHTPIN 4
#define DHTTYPE DHT22
#define ldrPin A0
#define ledPin 7
#define buttonPin 6
DHT dht(DHTPIN, DHTTYPE);
Servo vent;
LiquidCrystal_I2C lcd(0x27, 16, 2);
int screen = 0;
bool lastButton = HIGH;
unsigned long lastUpdate = 0;

void setup() {
  Serial.begin(9600);
  dht.begin();
  vent.attach(9);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  lcd.init();
  lcd.backlight();
}

void loop() {
  bool button = digitalRead(buttonPin);

  if (lastButton == HIGH && button == LOW) {
    screen++;
    if (screen > 3) screen = 0;
    delay(250); 
  }
  lastButton = button;
  int ldr = analogRead(ldrPin);
  float temp = dht.readTemperature();

  if (isnan(temp)) {
    Serial.println("DHT Error");
    return;
  }
  if (ldr < 500) digitalWrite(ledPin, HIGH);
  else digitalWrite(ledPin, LOW);

  if (temp < 28) vent.write(0);
  else if (temp <= 32) vent.write(90);
  else vent.write(180);

  if (millis() - lastUpdate > 1000) {
    lastUpdate = millis();

    lcd.clear();

    switch (screen) {

      case 0:
        lcd.setCursor(0, 0);
        lcd.print("Temperature:");
        lcd.setCursor(0, 1);
        lcd.print(temp);
        lcd.print(" C");
        break;

      case 1:
        lcd.setCursor(0, 0);
        lcd.print("Light Status:");
        lcd.setCursor(0, 1);
        lcd.print(ldr < 500 ? "ON" : "OFF");
        break;

      case 2:
        lcd.setCursor(0, 0);
        lcd.print("Vent:");
        lcd.setCursor(0, 1);
        if (temp < 28) lcd.print("Closed");
        else if (temp <= 32) lcd.print("Half Open");
        else lcd.print("Fully Open");
        break;

      case 3:
        lcd.setCursor(0, 0);
        lcd.print("Mode:");
        lcd.setCursor(0, 1);
        lcd.print("AUTO");
        break;
    }
  }
}
