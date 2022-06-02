#include "canHandler.h"
#include "mqttClient.h"
#include "Arduino.h"

canHandler can0(2,10);  //set INT and CS pin
wirelessDevice lteModule;

void setup()
{
  lteModule.virtualSerial->begin(115200); //Initialize virtual serial port
  Serial.begin(115200); //Initialize Arduino default serial port
  lteModule.connectCellularDevice();
  can0.initCANDevice();
}

long recieveTimer = 0; 
long rapidTransmitTimer = 0;
long slowTransmitTimer = 0;
long intervalRecieve = 20;
long intervalRapid = 70; 
long intervalSlow = 3455;
long now = 0;

void loop()
{
  
  now = millis();
  if(now > recieveTimer){
    recieveTimer = now + intervalRecieve;
    can0.recieveMessages();   
  }

  if(now > rapidTransmitTimer){
    rapidTransmitTimer = now + intervalRapid;
    lteModule.publishData(can0.vehicleSpeed->m_name, can0.vehicleSpeed->m_value);
    lteModule.publishData(can0.selectedGear->m_name, can0.selectedGear->m_value);
  }
  if(now > slowTransmitTimer){
    slowTransmitTimer = now + intervalSlow;
    lteModule.publishData(can0.batteryVoltage->m_name, can0.batteryVoltage->m_value);
    lteModule.publishData(can0.waterTemp->m_name, can0.waterTemp->m_value); 
  }
  

/*
  now = millis();

  if(now > recieveTimer){
    recieveTimer = now + intervalRecieve;
    
    if(logic == true){
      can0.vehicleSpeed->m_value = 50;
      can0.batteryVoltage->m_value = 12;
      can0.selectedGear->m_value = 2;
      can0.waterTemp->m_value = 30;
      logic = false;
    }
    else{
      can0.vehicleSpeed->m_value = 80;
      can0.batteryVoltage->m_value = 11;
      can0.selectedGear->m_value = 3;
      can0.waterTemp->m_value = 50;
      logic = true;
    }
    //can0.recieveMessages();   
  }

  if(now > rapidTransmitTimer){
    rapidTransmitTimer = now + intervalRapid;
    lteModule.publishData(can0.vehicleSpeed->m_name, can0.vehicleSpeed->m_value);
    lteModule.publishData(can0.selectedGear->m_name, can0.selectedGear->m_value);
  }
  if(now > slowTransmitTimer){
    slowTransmitTimer = now + intervalSlow;
    lteModule.publishData(can0.batteryVoltage->m_name, can0.batteryVoltage->m_value);
    lteModule.publishData(can0.waterTemp->m_name, can0.waterTemp->m_value);
  }
  */
}

