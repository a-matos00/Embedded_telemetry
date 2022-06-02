#include "Arduino.h"
#include <SoftwareSerial.h>

class wirelessDevice{
    public:
        SoftwareSerial* virtualSerial;

    wirelessDevice();
    void connectCellularDevice();
    void publishData(String topic1, int value1);
    void connectToBroker(); 
};