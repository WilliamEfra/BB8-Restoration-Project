#include <Arduino.h>
#include <WiFi.h>

const char *SSID = "BB8_Master";
const char *PASSWORD = "BB8_Master_7739376";
const unsigned long BAUDRATE = 115200;
const int SERVER_PORT = 4080;

WiFiClient TCPClient;

const IPAddress SERVER_IP(192, 168, 1, 4);

<<<<<<< HEAD
=======
void setupStation();
void reconnect();
void setup();
void loop();

>>>>>>> TCP
void setupStation()
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(SSID, PASSWORD);
  Serial.print(F("Connecting to BB8_Master"));
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(F("."));
    delay(1000);
  }
  Serial.println(F("Connected to BB8_Master"));
}

<<<<<<< HEAD
=======
void reconnect()
{
  Serial.println(F("Disconnected from BB8_Master"));
  Serial.print(F("Connecting to BB8_Master"));
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(F("."));
    delay(1000);
  }
  Serial.println(F("Connected to BB8_Master"));
}

>>>>>>> TCP
void setup()
{
  // put your setup code here, to run once:
  Serial.begin(BAUDRATE);
  setupStation();
  while (!TCPClient.connect(SERVER_IP, SERVER_PORT))
  {
    Serial.println(F("Failed to connect to server"));
    delay(1000);
  }
}

void loop()
{
  // put your main code here, to run repeatedly:
  while (TCPClient.connected())
  {
    TCPClient.write("Hello World\n");
  }
<<<<<<< HEAD
=======
  if (!WiFi.status() == WL_CONNECTED)
  {
    // TODO stop all actions
    reconnect();
  }
>>>>>>> TCP
  delay(200);
}
