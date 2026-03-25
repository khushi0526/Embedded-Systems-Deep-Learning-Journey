#define pirsensor 7
#define relay 8
int motionstate = 0;

void setup() {
  pinMode(pirsensor, INPUT);
  pinMode(relay, OUTPUT);
  Serial.begin(9600);
}

void loop() {
 motionstate = digitalRead(pirsensor);
 if(motionstate == HIGH){
  Serial.println("MOTION DETECTED");
  digitalWrite(relay, HIGH);
  delay(2000);
 }
 else{
  Serial.println("MOTION NOT DETECTED");
  digitalWrite(relay, LOW);
 }
 delay(200);
}
