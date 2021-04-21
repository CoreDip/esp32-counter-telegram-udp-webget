#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>
#include "AsyncUDP.h"

//Настройки WiFi
const char * ssid = "NeedSpeed";
const char * password = "ineedforspeed2018";
//Настройки WiFi

//Настройки Бота
#define BOT_TOKEN "1682745113:AAFe377VcJMiDNfBVaFBKEdTFafCUgU0URQ"
#define CHAT_ID "478429086"
//Настройки Бота

double Ivalue;
int Human_Counter_New;

AsyncUDP udp;
WiFiClientSecure secured_client;
UniversalTelegramBot bot(BOT_TOKEN, secured_client);

void setup() {
  Serial.begin(115200);
  Serial.println("1) Устройство запустилось.");
  WiFi.begin(ssid, password);
  secured_client.setCACert(TELEGRAM_CERTIFICATE_ROOT); // Add root certificate for api.telegram.org
  while (WiFi.status() != WL_CONNECTED){delay(500);}
  Serial.print("2) WiFi подключен. IP address: ");
  Serial.println(WiFi.localIP());

  //udp
  if(udp.listen(1234)) {
    Serial.println("3) UDP Запущен.");
    udp.onPacket([](AsyncUDPPacket packet) {
      String packetString = String( (char*) packet.data());
      Ivalue = packetString.toDouble();
    });
  }
  //udp

  bot.sendMessage(CHAT_ID, "Плата esp32 запущена!", "");
  pinMode(14, OUTPUT); //пищалка
  pinMode(25, INPUT_PULLUP); //кнопка сброса
}

void loop() {
  telegram();
  bip();
  counter();
}




  
