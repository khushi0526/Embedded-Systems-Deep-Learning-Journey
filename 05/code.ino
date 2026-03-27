#define ldrPin A0
#define pirPin 2
#define ledPin 8
int ldrValue = 0;
int motion = 0;
int threshold = 500;

unsigned long lastMotionTime = 0;
int delayTime = 5000;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  delay(2000);
}

void loop() {
 ldrValue = analogRead(ldrPin);
 motion = digitalRead(pirPin);
  Serial.print("LDR: ");
  Serial.print(ldrValue);
  Serial.print(" Motion: ");
  Serial.println(motion);
  if(ldrValue < threshold && motion == HIGH){
    digitalWrite(ledPin, HIGH);
    lastMotionTime = millis();
  }
  if(millis() - lastMotionTime > delayTime){
    digitalWrite(ledPin, LOW);
  }
}
