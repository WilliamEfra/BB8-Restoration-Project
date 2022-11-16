#include <Arduino.h>
#include <WiFi.h>
#include "AsyncUDP.h"

const char *ssid = "BB8_Master";
const char *password = "BB8_Master_7739376";

// Variables
bool sendCmd = false;
String slaveCmd = "0";
String slaveState = "0";

// WiFi stuff
WiFiServer server(80);
WiFiClient browser;
IPAddress ip(192, 168, 1, 4);
IPAddress gateway(192, 168, 1, 254);
IPAddress subnet(255, 255, 255, 0);

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.mode(WIFI_AP_STA);
  WiFi.config(ip, gateway, subnet);
  WiFi.softAP("BB8", "ThisIsAPassword123");
  WiFi.localIP();
}

void loop()
{
  // put your main code here, to run repeatedly:

  delay(200);
}