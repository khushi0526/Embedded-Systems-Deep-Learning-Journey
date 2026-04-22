#define ldrPin A0
#define ledPin 7
bool mode = 0; 
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int ldr = analogRead(ldrPin);

  if (Serial.available()) {
    char cmd = Serial.read();

    if (cmd == 'A') {
      mode = 0;
      Serial.println("AUTO MODE");
    }

    else if (cmd == 'M') {
      mode = 1;
      Serial.println("MANUAL MODE");
    }

    else if (mode == 1) {
      if (cmd == '1') {
        digitalWrite(ledPin, HIGH);
      }
      else if (cmd == '0') {
        digitalWrite(ledPin, LOW);
      }
    }
  }

  if (mode == 0) {
    if (ldr < 500) {
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(ledPin, LOW);
    }
  }
  Serial.print("LDR: ");
  Serial.println(ldr);
  delay(500);
}
