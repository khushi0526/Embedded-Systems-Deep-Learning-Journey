#include <Servo.h>
#define trigPin 9
#define echoPin 10
Servo doorServo;
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  doorServo.attach(6);
  Serial.begin(9600);

}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  if(distance < 20){
    doorServo.write(90);
  }
  else{
    doorServo.write(0);
  }
  delay(200);

}
