#define ldrPin A0
#define pirPin 4
#define relayPin 8
#define buttonPin 7
int ldrValue = 0;
int motion = 0;
int threshold = 500;
bool autoMode = true;
bool lightState = true;

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
  
  if(digitalRead(buttonPin) == LOW){
    autoMode = !autoMode;
    delay(300);
  }

  if(autoMode){
    if(ldrValue > threshold && motion == HIGH){
      lightState = true;
    }
    else{
      lightState = false;
    }
  }
  else{
    if(digitalRead(buttonPin) == HIGH){
      lightState = !lightState;
      delay(300);
    }
  }
  digitalWrite(relayPin, lightState ? LOW:HIGH);

  Serial.print("MODE: ");
  Serial.print(autoMode ? "AUTO" : "MANUAL");
  Serial.print(" LIGHT: ");
  Serial.println(lightState);
  delay(2000);
}
