#include "BluetoothBody.hpp"

BluetoothBody::BluetoothBody(String name, String connectToName)
{
    this->name = name;
    this->connectToName = connectToName;
    this->SerialBT;
    const char *pincode = "22331";
    SerialBT.begin();
    // To prevent unauthorized connections to the device
    SerialBT.setPin(pincode);
}

String BluetoothBody::getName()
{
    return (this->name);
}

String BluetoothBody::getConnectToName()
{
    return (this->connectToName);
}

void BluetoothBody::connect()
{
}

void BluetoothBody::connect(String connectToName)
{
}