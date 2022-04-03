#include "user_functions.h"

void setup()
{
  Serial.begin(9600);
  Serial.println("Application started...");
  initCANDevice();
}

void loop()
{
  recieveMessages();  //recieve CAN messages and display them in the serial monitor
}


