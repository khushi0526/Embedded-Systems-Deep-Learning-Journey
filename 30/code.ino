#define irPin 2
#define ledPin 7
#define buzzerPin 8

void setup() {
  pinMode(irPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int irState = digitalRead(irPin);
  Serial.print("IR: ");
  Serial.println(irState);

  if (irState == HIGH) {
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 1500);
    delay(200);
    noTone(buzzerPin);
    delay(200);
  }
  else {
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
  }
}
