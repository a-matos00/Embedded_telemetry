#include "Arduino.h"
#include <SoftwareSerial.h>

class wirelessDevice{
    public:
        SoftwareSerial* virtualSerial;

    wirelessDevice();
    void connectCellularDevice();
    void publishData(String topic1, int value1, String topic2, int value2);
    void connectToBroker(); 
};