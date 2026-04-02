#define ldrPin A0
#define pirPin 4
#define relayPin 8
#define buttonPin 7

int ldrValue = 0;
int motion = 0;
int threshold = 500;

bool autoMode = true;
bool lightState = false;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);
  delay(2000);
}

void loop() {
  ldrValue = analogRead(ldrPin);
  motion = digitalRead(pirPin);

  // Mode toggle
  if (digitalRead(buttonPin) == LOW) {
    autoMode = !autoMode;
    delay(300);
  }

  // Logic
  if (autoMode) {
    if (ldrValue < threshold && motion == HIGH) {
      lightState = true;
    } else {
      lightState = false;
    }
  } else {
    if (digitalRead(buttonPin) == LOW) {
      lightState = !lightState;
      delay(300);
    }
  }

  digitalWrite(relayPin, lightState ? LOW : HIGH);

  // Clean structured output
  Serial.print("Mode: ");
  Serial.print(autoMode ? "AUTO" : "MANUAL");
  Serial.print(" | LDR: ");
  Serial.print(ldrValue);
  Serial.print(" | Motion: ");
  Serial.print(motion);
  Serial.print(" | Light: ");
  Serial.println(lightState ? "ON" : "OFF");

  delay(500);
}
