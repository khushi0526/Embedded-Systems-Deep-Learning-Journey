#define ldrPin A0
#define ledPin 9
int threshold = 500;
int ldrValue = 0;
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  int sum = 0;
  for (int i = 0; i < 10; i++) {
    sum += analogRead(ldrPin);
    delay(5);
  }
  ldrValue = sum / 10; 
  Serial.print("Filtered LDR: ");
  Serial.println(ldrValue);
  if (ldrValue < threshold) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  delay(200);
}
