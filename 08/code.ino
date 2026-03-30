#define relayPin 8
void setup() {
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  digitalWrite(relayPin, HIGH); 
  Serial.println("Relay ON");
  delay(3000);
  digitalWrite(relayPin, LOW);  
  Serial.println("Relay OFF");
  delay(3000);
}
