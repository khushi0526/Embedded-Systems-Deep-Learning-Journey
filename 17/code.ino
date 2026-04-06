#define irPin 3
#define ledPin 7
int objectDetected = 0;
void setup() {
  pinMode(irPin, INPUT);
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  objectdetected = digitalRead(irPin);
  Serial.print("IR: ");
  Serial.println(objectDetected);
  if(objectDetected == LOW){
    digitalWrite(ledPin, HIGH);
  }
  else{
    digitalWrite(ledPin, LOW);
  }
  delay(100);

}
