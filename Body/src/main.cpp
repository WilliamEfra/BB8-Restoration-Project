#include <Arduino.h>
#include <WiFi.h>

#define SSID "BB8_Master"
#define PASSWORD "BB8_Master_7739376"
#define BAUDRATE 115200
#define SERVER_PORT 4080

WiFiServer TCPServer(SERVER_PORT);
WiFiClient TCPClient;

// WiFi stuff, this is specific to the Master
IPAddress ip(192, 168, 1, 4);
IPAddress gateway(192, 168, 1, 254);
IPAddress subnet(255, 255, 255, 0);

void setupAP();
void reconnect();
void getSlaveMessage();
void setup();
void loop();

void setupAP()
{
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(ip, gateway, subnet);
  WiFi.softAP(SSID, PASSWORD);
  Serial.println(F("Started AP with SSID BB8_Master and PASSWORD BB8_Master_7739376"));
  Serial.print(F("Waiting for connection from slave"));
  // Wait for connection from slave
  while (WiFi.softAPgetStationNum() == 0)
  {
    Serial.print(F("."));
    delay(1000);
  }

  Serial.println(F("\nConnected to slave"));
}

void reconnect()
{
  Serial.println(F("Slave disconnected"));
  Serial.print(F("Waiting for connection from slave"));
  while (WiFi.softAPgetStationNum() == 0)
  {
    Serial.print(F("."));
    delay(1000);
  }
  Serial.println(F("\nConnected to slave"));
}

void getSlaveMessages()
{
  if (TCPClient.available())
  {
    char c = TCPClient.read();
    Serial.print(c);
  }
}

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(BAUDRATE);
  setupAP();
  TCPServer.begin();
}

void loop()
{
  // put your main code here, to run repeatedly:
  TCPClient = TCPServer.available();
  if (TCPClient)
  {
    Serial.println(F("Client connected"));
    while (TCPClient.connected())
    {
      getSlaveMessages();
    }
    Serial.println(F("Client disconnected"));
    TCPClient.stop();
  }
  // Attempt reconnect to station if disconnected
  if (!WiFi.softAPgetStationNum())
  {
    // TODO Add some code to stop any and all actions while disconnected
    reconnect();
  }

  delay(200);
}