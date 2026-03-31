#define pirPin 4
#define relayPin 8
int motion = 0;
void setup() {
  pinMode(pirPin, INPUT);
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);
  delay(2000);

}

void loop() {
  motion = digitalRead(pirPin);
  Serial.print("Motion: ");
  Serial.println(motion);
  if(motion == HIGH){
    digitalWrite(relayPin, HIGH);
  }
  else{
    digitalWrite(relayPin, LOW);
  }
  delay(2000);

}
