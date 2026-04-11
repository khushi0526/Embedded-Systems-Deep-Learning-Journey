#include <DHT.h>
#include <Servo.h>
#define DHTPIN 4
#define DHTTYPE DHT22
#define ldrPin A0
#define ledPin 7
#define buzzerPin 8
DHT dht(DHTPIN, DHTTYPE);
Servo vent;

void setup() {
  Serial.begin(9600);
  dht.begin();
  vent.attach(9);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int ldrValue = analogRead(ldrPin);
  if (ldrValue < 500) {
    digitalWrite(ledPin, HIGH); 
  } else {
    digitalWrite(ledPin, LOW);  
  }

  float temp = dht.readTemperature();
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print("  LDR: ");
  Serial.println(ldrValue);

  if (temp < 28) {
    vent.write(0);
    noTone(buzzerPin);
  }

  else if (temp >= 28 && temp <= 32) {
    vent.write(90);
    noTone(buzzerPin);
  }

  else {
    vent.write(180);
    tone(buzzerPin, 2000);
    delay(150);
    noTone(buzzerPin);
    delay(150);
  }

  delay(200);
}
