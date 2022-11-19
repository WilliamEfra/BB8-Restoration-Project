#include <Arduino.h>
#include <WiFi.h>

const char *SSID = "BB8_Master";
const char *PASSWORD = "BB8_Master_7739376";
const unsigned long BAUDRATE = 115200;
const int SERVER_PORT = 4080;

WiFiServer TCPServer(SERVER_PORT);
<<<<<<< HEAD
=======
WiFiClient TCPClient;
>>>>>>> TCP

// WiFi stuff, this is specific to the Master
IPAddress ip(192, 168, 1, 4);
IPAddress gateway(192, 168, 1, 254);
IPAddress subnet(255, 255, 255, 0);

<<<<<<< HEAD
=======
void setupAP();
void reconnect();
void getSlaveMessage();
void setup();
void loop();

>>>>>>> TCP
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
<<<<<<< HEAD

=======
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
>>>>>>> TCP
  Serial.println(F("\nConnected to slave"));
}

void getSlaveMessages()
{
<<<<<<< HEAD
=======
  if (TCPClient.available())
  {
    char c = TCPClient.read();
    Serial.print(c);
  }
>>>>>>> TCP
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
<<<<<<< HEAD
  WiFiClient TCPClient = TCPServer.available();
=======
  TCPClient = TCPServer.available();
>>>>>>> TCP
  if (TCPClient)
  {
    Serial.println(F("Client connected"));
    while (TCPClient.connected())
    {
<<<<<<< HEAD
      if (TCPClient.available())
      {
        char c = TCPClient.read();
        Serial.print(c);
      }
=======
      getSlaveMessages();
>>>>>>> TCP
    }
    Serial.println(F("Client disconnected"));
    TCPClient.stop();
  }
<<<<<<< HEAD
=======
  // Attempt reconnect to station if disconnected
  if (!WiFi.softAPgetStationNum())
  {
    // TODO Add some code to stop any and all actions while disconnected
    reconnect();
  }

>>>>>>> TCP
  delay(200);
}