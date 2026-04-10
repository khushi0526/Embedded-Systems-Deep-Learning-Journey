#include <DHT.h>
#include <Servo.h>
#define DHTPIN 4
#define DHTTYPE DHT22
#define buzzerPin 8
DHT dht(DHTPIN, DHTTYPE);
Servo ventServo;
void setup() {
  Serial.begin(9600);
  dht.begin();
  ventServo.attach(9); 
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  float temp = dht.readTemperature();
  Serial.print("Temp: ");
  Serial.println(temp);
  if (temp < 28) {
    ventServo.write(0);
    noTone(buzzerPin);
  }
  else if (temp >= 28 && temp <= 32) {
    ventServo.write(90);
    tone(buzzerPin, 1000);
    delay(500);
    noTone(buzzerPin);
    delay(500);
  }
  else {
    ventServo.write(180);
    tone(buzzerPin, 2000);
    delay(150);
    noTone(buzzerPin);
    delay(150);
  }

  delay(200);
}
