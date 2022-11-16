#include <Arduino.h>
#include "BluetoothSerial.h"
#include "BluetoothBody.hpp"

BluetoothSerial SerialBT;

void setup()
{
  // put your setup code here, to run once:
  BluetoothBody reciever = BluetoothBody("tempName", "tempConnectToName");
  Serial.begin(115200);
  Serial.println("Bluetooth Started! Ready to pair...");
}

void loop()
{
  // put your main code here, to run repeatedly:
  while (!SerialBT.connected())
  {
    SerialBT.connect("MasterBluetoothBB8");
  }
  if (Serial.available())
  {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available())
  {
    Serial.write(SerialBT.read());
  }
  delay(20);
}