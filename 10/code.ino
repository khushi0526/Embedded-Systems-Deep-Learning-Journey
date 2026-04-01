#define ldrPin A0
#define pirPin 4
#define relayPin 8
int ldrValue = 0;
int motion = 0;
int threshold = 500;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(relayPin, OUTPUT);
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
  if(ldrValue > threshold && motion == HIGH){
    digitalWrite(relayPin, HIGH);
  }
  else{
    digitalWrite(relayPin, LOW);
  }
  delay(200);

}
