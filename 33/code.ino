#include <Wire.h>
#include <RTClib.h>
RTC_DS3231 rtc;
#define ledPin 7

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  if (!rtc.begin()) {
    Serial.println("RTC not found");
    while (1);
  }
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

void loop() {
  DateTime now = rtc.now();
  Serial.print("Time: ");
  Serial.print(now.hour());
  Serial.print(":");
  Serial.print(now.minute());
  Serial.print(":");
  Serial.println(now.second());

  if (now.hour() >= 18 || now.hour() < 6) {
    digitalWrite(ledPin, HIGH); 
  } else {
    digitalWrite(ledPin, LOW);  
  }

  delay(1000);
}
