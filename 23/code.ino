#include <DHT.h>
#include <Servo.h>
#define DHTPIN 4
#define DHTTYPE DHT22
#define buttonPin 7
DHTdht(DHTPIN, DHTTYPE);
Servo s;
bool mode = 0;
bool lastButton = HIGH;
bool servoState = 0;

void setup() {
  Serial.begin(9600);
  dht.begin();
  s.attach(9);
  pinMode(buttonPin, INPUT_PULLUP);

}

void loop() {
  bool currentButton = digitalRead(buttonPin);
  if(lastButton == HIGH && currentButton == LOW){
    mode = !mode;
    Serial.println(mode ? "MANUAL MODE" : "AUTO MODE");
    delay(300);
  }
  lastButton = currentButton;
  if(mode == 0){
    float temp = dht.readTemperature();
    Serial.print("Temp: ");
    Serial.println(temp);
    if(temp < 28){
      s.write(0);
    }
    else{
      s.write(90);
    }
  }
  else{
    if(currentButton == LOW){
      servoState = !servoState;
      s.write(servoState ? 90 : 0);
      delay(300);
    }
  }

}
