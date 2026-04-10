#include <DHT.h>
#define DHTPIN 4
#define DHTTYPE DHT22
#define ledPin 8
#define buzzerPin 9
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  dht.begin();

}

void loop() {
  float temp = dht.readTemperature();
  Serial.print("Temp: ");
  Serial.println(temp);
  if(temp < 28){
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
  }
  else if(temp >= 28 && temp <= 32){
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 1000);
    delay(500);
    noTone(buzzerPin);
    delay(500);
  }
  else{
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 2000);
    delay(500);
    noTone(buzzerPin);
    delay(150);
  }
  delay(200);

}
