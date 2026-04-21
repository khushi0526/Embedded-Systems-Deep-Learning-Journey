#include <Servo.h>
#define ledPin 7
Servo s;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  s.attach(9);
  Serial.println("System Ready");
}

void loop() {
  if (Serial.available()) {

    char cmd = Serial.read();
    if (cmd == '1') {
      digitalWrite(ledPin, HIGH);
      Serial.println("LED ON");
    }
    else if (cmd == '0') {
      digitalWrite(ledPin, LOW);
      Serial.println("LED OFF");
    }
    else if (cmd == 'S') {
      s.write(0);
      Serial.println("Servo 0°");
    }
    else if (cmd == 'M') {
      s.write(90);
      Serial.println("Servo 90°");
    }
    else if (cmd == 'F') {
      s.write(180);
      Serial.println("Servo 180°");
    }
  }
}
