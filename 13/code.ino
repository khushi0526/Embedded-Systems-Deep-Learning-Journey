#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define ldrPin A0
#define pirPin 4
#define relayPin 8
#define buttonPin 7
LiquidCrystal_I2C lcd(0x27, 16, 2);
int ldrValue = 0;
int motion = 0;
int threshold = 500;
bool autoMode = true;
bool lightState = false;
void setup() {
  pinMode(pirPin, INPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  delay(2000);
}

void loop() {
  ldrValue = analogRead(ldrPin);
  motion = digitalRead(pirPin);

  if(digitalRead(buttonPin) == LOW){
    autoMode = !autoMode;
    delay(300);
  }
  if(autoMode){
    if(ldrValue < threshold && motion == HIGH){
      lightState = !lightState;
      delay(300);
    }
  }
  digitalWrite(relayPin, lightState ? LOW:HIGH);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(autoMode ? "Auto ": "Manual ");
  lcd.print(lightState ? "ON ":"OFF");
  lcd.setCursor(0, 1);
  lcd.print("L: ");
  lcd.print(ldrValue);
  lcd.print(" M: ");
  lcd.print(motion);

  delay(500);
}

