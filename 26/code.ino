#include <DHT.h>
#include <Servo.h>
#include <LiquidCrystal.h>
#define DHTPIN 4
#define DHTTYPE DHT11
#define ldrPin A0
#define ledPin 7
#define buzzerPin 8
#define buttonPin 6
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
DHT dht(DHTPIN, DHTTYPE);
Servo vent;
bool mode = 0;
bool lastButton = HIGH;

void setup() {
  Serial.begin(9600);
  dht.begin();
  vent.attach(9);

  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  lcd.begin(16, 2);
}

void loop() {

  bool button = digitalRead(buttonPin);

  // Toggle mode
  if (lastButton == HIGH && button == LOW) {
    mode = !mode;
    delay(300);
  }
  lastButton = button;

  int ldr = analogRead(ldrPin);
  float temp = dht.readTemperature();

  String lightStatus = "";
  String ventStatus = "";

  if (mode == 0) {
    // AUTO MODE

    if (ldr < 500) {
      digitalWrite(ledPin, HIGH);
      lightStatus = "Light:ON";
    } else {
      digitalWrite(ledPin, LOW);
      lightStatus = "Light:OFF";
    }

    if (temp < 28) {
      vent.write(0);
      ventStatus = "Vent:CLOSE";
      noTone(buzzerPin);
    }
    else if (temp <= 32) {
      vent.write(90);
      ventStatus = "Vent:MID";
    }
    else {
      vent.write(180);
      ventStatus = "Vent:OPEN";
      tone(buzzerPin, 2000);
      delay(150);
      noTone(buzzerPin);
      delay(150);
    }
  }

  // LCD Display
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temp);
  lcd.print(" ");
  lcd.print(mode ? "MAN" : "AUTO");

  lcd.setCursor(0, 1);
  lcd.print(lightStatus);
  lcd.print(" ");
  lcd.print(ventStatus);

  delay(500);
}
