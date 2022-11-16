#include <Arduino.h>
#include <WiFi.h>

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Bluetooth Started! Ready to pair...");
}

void loop()
{
  // put your main code here, to run repeatedly:
  /* while (!Bluetooth.isConnected())
  {
    SerialBT.connect("MasterBluetoothBB8");
  } */
  delay(20);
}