#include "Arduino.h"
#include <SoftwareSerial.h>

class wirelessDevice{
    public:
        SoftwareSerial* virtualSerial;

    wirelessDevice();
    void connectCellularDevice();
    void publishData();
    void connectToBroker(); 
};