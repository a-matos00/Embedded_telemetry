#include "canHandler.h"
#include "mqttClient.h"

canHandler can0(2,10);  //set INT and CS pin
wirelessDevice lteModule;
void setup()
{
  lteModule.virtualSerial->begin(115200); //Initialize virtual serial port
  Serial.begin(115200); //Initialize Arduino default serial port
  lteModule.connectCellularDevice();
  //can0.initCANDevice();
}

void loop()
{
  lteModule.publishData();
  //can0.recieveMessages();  //recieve CAN messages and display them in the serial monitor
}

