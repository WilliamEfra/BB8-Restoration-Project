#include "BluetoothSerial.h"

#ifndef BLUETOOTHBODY_HPP
#define BLUETOOTHBODY_HPP

class BluetoothBody
{
private:
    String name;
    String connectToName;
    BluetoothSerial SerialBT;

public:
    BluetoothBody(String name, String connectToName);
    void connect();
    void connect(String connectToName);
    String getName();
    String getConnectToName();
    bool isConnected();
};

#endif // BLUETOOTHRCV_HPP