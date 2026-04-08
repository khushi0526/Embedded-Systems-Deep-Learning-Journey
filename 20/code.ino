#include <WiFi.h>
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";
WiFiServer server(80);
#define ledPin 2

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
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
    String request = client.readStringUntil('\r');
    client.flush();
    if (request.indexOf("/ON") != -1) {
      digitalWrite(ledPin, HIGH);
    }
    if (request.indexOf("/OFF") != -1) {
      digitalWrite(ledPin, LOW);
    }
    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/html");
    client.println();
    client.println("<h1>ESP32 LED Control</h1>");
    client.println("<a href=\"/ON\"><button>ON</button></a>");
    client.println("<a href=\"/OFF\"><button>OFF</button></a>");
    client.println();
    client.stop();
  }
}
