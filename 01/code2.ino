int ldrPin = A0;
int ledPin = 2;
void setup() {
pinMode(ledPin, OUTPUT);
Serial.begin(9600);
}
void loop() {
  int ldrValue = analogRead(ldrPin);
  int brightness = map(ldrValue, 0, 1023, 255, 0);
  analogWrite(ledPin, brightness);
  Serial.println("LDR: ");
  Serial.println(ldrValue);
  Serial.println("Brightness: ");
  Serial.println(brightness);
  delay(200);
}
