#include <DHT.h>
#include <Servo.h>
#define DHTPIN 4
#define DHTTYPE DHT11
#define ldrPin A0
#define ledPin 7
#define buzzerPin 8
#define buttonPin 6
DHT dht(DHTPIN, DHTTYPE);
Servo vent;
bool mode = 0; 
bool lastButton = HIGH;
bool ledState = 0;
bool servoState = 0;

void setup() {
  Serial.begin(9600);
  dht.begin();
  vent.attach(9);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {

  bool button = digitalRead(buttonPin)
  if (lastButton == HIGH && button == LOW) {
    mode = !mode;
    Serial.println(mode ? "MANUAL MODE" : "AUTO MODE");
    delay(300);
  }
  lastButton = button;

  if (mode == 0) {
    int ldr = analogRead(ldrPin);
    float temp = dht.readTemperature();

    if (ldr < 500) digitalWrite(ledPin, HIGH);
    else digitalWrite(ledPin, LOW);

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
      delay(150);
    }
  }

  else {
    if (button == LOW) {
      ledState = !ledState;
      servoState = !servoState;
      digitalWrite(ledPin, ledState);
      vent.write(servoState ? 90 : 0);
      delay(300);
    }

    noTone(buzzerPin); 
  }
}
