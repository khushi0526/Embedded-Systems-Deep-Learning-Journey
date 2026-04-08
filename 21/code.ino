#include <WiFi.h>
#include <DHT.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

WiFiServer server(80);

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {
  WiFiClient client = server.available();

  if (client) {
    float temp = dht.readTemperature();
    float hum = dht.readHumidity();

    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/html");
    client.println();

    client.println("<h1>Environment Monitor</h1>");
    client.print("<p>Temperature: ");
    client.print(temp);
    client.println(" °C</p>");

    client.print("<p>Humidity: ");
    client.print(hum);
    client.println(" %</p>");

    client.println();
    client.stop();
  }
}
