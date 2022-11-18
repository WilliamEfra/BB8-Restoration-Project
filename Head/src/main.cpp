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
WiFiClient browser;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(baudRate);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print(F("Connecting to BB8_Master"));
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(F("."));
    delay(1000);
  }
}

void loop()
{
  // put your main code here, to run repeatedly:
  delay(200);
}