#include "user_functions.h"
#include "data.h"

#define CAN_DEVICE_INT 2
 
long unsigned int message_id;
unsigned char DLC;
unsigned char rxBuf[8];
char msgString[128];
MCP_CAN CAN_DEVICE(10); 

Data rpm(0,2,1,1);

void recieveMessages(){
      
    if(!digitalRead(CAN_DEVICE_INT))                         // If CAN_DEVICE_INT pin is low, read receive buffer
    {
        CAN_DEVICE.readMsgBuf(&message_id, &DLC, rxBuf);      // Read data: DLC = data length, buf = data byte(s)
        displayRxMessage(); //display recieved message in serial monitor
        readData(message_id, rxBuf);
    }
}

void readData(unsigned long int id, unsigned char* data){
  if( id == RPM_ID){
    rpm.getValue(data);
    Serial.println(rpm.m_value);
  }
}

void displayRxMessage(){
  sprintf(msgString, "Standard ID: 0x%.3lX       DLC: %1d  Data:", message_id, DLC);
  
  Serial.print(msgString);
  
  for(byte i = 0; i<DLC; i++){
    sprintf(msgString, " 0x%.2X", rxBuf[i]);
    Serial.print(msgString);
  }

  Serial.println();
}

void initCANDevice(){
  // Initialize MCP2515 running at 16MHz with a baudrate of 500kb/s and the masks and filters disabled.
  if(CAN_DEVICE.begin(MCP_ANY, CAN_500KBPS, MCP_16MHZ) == CAN_OK)
    Serial.println("MCP2515 Initialized Successfully!");
  else
    Serial.println("Error Initializing MCP2515...");
  
  CAN_DEVICE.setMode(MCP_NORMAL);                     // Set operation mode to normal so the MCP2515 sends acks to received data.

  pinMode(CAN_DEVICE_INT, INPUT);                            // Configuring pin for /INT input
}