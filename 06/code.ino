#define ldrPin A0
#define pirPin 4
#define ledPin 9
int ldrValue = 0;
int motion = 0;
int threshold = 500;
enum State { IDLE, MOTION_DETECTED, LIGHT_ON };
State currentState = IDLE;
unsigned long lastMotionTime = 0;
unsigned long lightDelay = 5000; 
void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  delay(2000); // PIR stabilization
}
void loop() {
  ldrValue = analogRead(ldrPin);
  motion = digitalRead(pirPin);

  switch (currentState) {
    case IDLE:
      if (ldrValue < threshold && motion == HIGH) {
        currentState = MOTION_DETECTED;
        lastMotionTime = millis();
        Serial.println("State: MOTION_DETECTED");
      }
      break;

    case MOTION_DETECTED:
      digitalWrite(ledPin, HIGH);
      if (motion == LOW) {
        currentState = LIGHT_ON;
        Serial.println("State: LIGHT_ON");
      }
      break;

    case LIGHT_ON:
      digitalWrite(ledPin, HIGH);
      if (millis() - lastMotionTime > lightDelay) {
        currentState = IDLE;
        Serial.println("State: IDLE");
      }
      break;
  }

  Serial.print("LDR: ");
  Serial.print(ldrValue);
  Serial.print("  Motion: ");
  Serial.println(motion);
  delay(200);
}
