#include <DHT.h>
#define DHTPIN 7
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);
  dht.begin();

}

void loop() {
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  if(isnan(temp) || isnan(hum)){
    Serial.println("Failed to read");
    return;
  }
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" Hum: ");
  Serial.println(hum);
  delay(1000);
}
