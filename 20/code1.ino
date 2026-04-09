//Telegram Code
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASSWORD";
#define BOT_TOKEN "YOUR_BOT_TOKEN"
#define CHAT_ID "YOUR_CHAT_ID"
WiFiClientSecure client;
UniversalTelegramBot bot(BOT_TOKEN, client);
#define ledPin 2

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  client.setInsecure();
  Serial.println("\nConnected!");
}

void loop() {
  int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
  while (numNewMessages) {
    for (int i = 0; i < numNewMessages; i++) {
      String text = bot.messages[i].text;
      if (text == "/on") {
        digitalWrite(ledPin, HIGH);
        bot.sendMessage(CHAT_ID, "LED ON", "");
      }
      if (text == "/off") {
        digitalWrite(ledPin, LOW);
        bot.sendMessage(CHAT_ID, "LED OFF", "");
      }
    }
    numNewMessages = bot.getUpdates(bot.last_message_received + 1);
  }
  delay(1000);
}
