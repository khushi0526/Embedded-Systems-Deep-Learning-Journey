int trigPin = 3;
int echoPin = 2;
int buzzer = 8;
void setup() {
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(buzzer, OUTPUT);
Serial.begin(9600);
}

void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

long duration = pulseIn(echoPin, HIGH);
int distance = duration*0.034 / 2;

Serial.println("Distance");
Serial.println(distance);

if(distance < 20){
  digitalWrite(buzzer, HIGH);
}
else{
  digitalWrite(buzzer, LOW);
}
delay(2000);
}
