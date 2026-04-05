#include <Servo.h>
#define potPin A0
Servo myServo;
int potValue = 0;
int angle = 0;

void setup() {
  myServo.attach(9);
  Serial.begin(9600);

}

void loop() {
  potValue = analogRead(potPin);
  angle = map(potValue, 0, 1023, 0, 180);
  myServo.write(angle);
  Serial.print("Pot: ");
  Serial.print(potValue);
  Serial.print(" Angle: ");
  Serial.println(angle);
  delay(100);

}
