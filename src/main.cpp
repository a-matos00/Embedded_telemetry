#include "canHandler.h"

canHandler can0(2,10);  //set INT and CS pin

void setup()
{
  Serial.begin(9600);
  Serial.println("Application started...");
  can0.initCANDevice();
}

void loop()
{
  can0.recieveMessages();  //recieve CAN messages and display them in the serial monitor
}