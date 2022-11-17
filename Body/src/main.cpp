#include <Arduino.h>
#include <WiFi.h>

const char *ssid = "BB8_Master";
const char *password = "BB8_Master_7739376";
const unsigned long baudRate = 115200;

// Variables
bool sendCmd = false;
String slaveCmd = "0";
String slaveState = "0";

// WiFi stuff, this is specific to the Master, the slave needs a different IP address
WiFiServer server(80);
WiFiClient browser;
IPAddress ip(192, 168, 1, 4);
IPAddress gateway(192, 168, 1, 254);
IPAddress subnet(255, 255, 255, 0);

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(baudRate);
  WiFi.mode(WIFI_AP);
  WiFi.config(ip, gateway, subnet);
  WiFi.softAP(ssid, password);
  Serial.println(F("Started AP with SSID BB8_Master and PASSWORD BB8_Master_7739376"));
  Serial.print(F("Waiting for connection from slave"));
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(F("."));
    delay(200);
  }
}

void loop()
{
  // put your main code here, to run repeatedly:
  delay(200);
}