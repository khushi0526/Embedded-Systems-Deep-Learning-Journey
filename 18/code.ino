#define buzzerPin 8
void setup() {
  pinMode(buzzerPin, OUTPUT);

}

void loop() {
  tone(buzzerPin, 1000);
  delay(500);
  noTone(buzzerPin);
  delay(500);
  tone(buzzerPin, 1500);
  delay(500);
  noTone(buzzerPin);
  delay(500);
  tone(buzzerPin, 262); 
  delay(300); 
  tone(buzzerPin, 294); 
  delay(300); 
  tone(buzzerPin, 330); 
  delay(300); 
  tone(buzzerPin, 349); 
  delay(300); 
  noTone(buzzerPin);
  delay(1000);

}
