#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#define DHTPIN 4
#define DHTTYPE DHT22
#define ldrPin A0
#define ledPin 7
#define buzzerPin 8
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  dht.begin();
  lcd.init();
  lcd.backlight();
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  float temp = dht.readTemperature();
  int ldr = analogRead(ldrPin);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.print(temp);
  lcd.setCursor(0, 1);
  lcd.print("Light:");
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
