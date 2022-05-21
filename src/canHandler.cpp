#include "canHandler.h"

canHandler::canHandler(uint8_t INT_pin, uint8_t CS_pin){
  waterTemp = new Data("wat",0,2,1,0);
  selectedGear = new Data("gea", 0,2,1,0);
  vehicleSpeed = new Data("spe", 0,2,1,0);
  batteryVoltage = new Data("bat", 0,2,1,0);
  CAN_DEVICE = new MCP_CAN(CS_pin);
  m_INT_pin = INT_pin;
}

void canHandler::recieveMessages(){
      
    if(!digitalRead(m_INT_pin))                         // If CAN_DEVICE_INT pin is low, read receive buffer
    {
        CAN_DEVICE->readMsgBuf(&message_id, &DLC, rxBuf);      // Read data: DLC = data length, buf = data byte(s)
        displayRxMessage(); //display recieved message in serial monitor
        readData(message_id, rxBuf);  //Get data values from CAN message
    }
}

void canHandler::readData(unsigned long int id, unsigned char* data){
  switch(id){
    case 123: batteryVoltage->getValue(data);
              Serial.println(batteryVoltage->m_value);
              break;
    case 124: waterTemp->getValue(data);
              Serial.println(waterTemp->m_value);
              break;
    case 125: selectedGear->getValue(data);
              Serial.println(selectedGear->m_value);
              break;
    case 126: vehicleSpeed->getValue(data);
              Serial.println(vehicleSpeed->m_value);
              break;
  }
}

void canHandler::displayRxMessage(){
  sprintf(msgString, "Standard ID: 0x%.3lX       DLC: %1d  Data:", message_id, DLC);
  
  Serial.print(msgString);
  
  for(byte i = 0; i<DLC; i++){
    sprintf(msgString, " 0x%.2X", rxBuf[i]);
    Serial.print(msgString);
  }

  Serial.println();
}

void canHandler::initCANDevice(){
  // Initialize MCP2515 running at 16MHz with a baudrate of 500kb/s and the masks and filters disabled.
  if(CAN_DEVICE->begin(MCP_ANY, CAN_500KBPS, MCP_8MHZ) == CAN_OK)
    Serial.println("MCP2515 Initialized Successfully!");
  else
    Serial.println("Error Initializing MCP2515...");
  
  CAN_DEVICE->setMode(MCP_NORMAL);                     // Set operation mode to normal so the MCP2515 sends acks to received data.

  pinMode(m_INT_pin, INPUT);                            // Configuring pin for /INT input
}