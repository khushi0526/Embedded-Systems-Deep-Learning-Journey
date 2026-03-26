#define ldrPin A0
#define pirPin 4
#define ledPin 9
int ldrValue = 0;
int motion = 0;
int threshold = 500;
void setup() {
 pinMode(pirPin, INPUT);
 pinMode(ledPin, OUTPUT);
Serial.begin(9600);
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
}
else{
  digitalWrite(ledPin, LOW);
}
delay(2000);
}
