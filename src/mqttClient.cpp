#include <mqttClient.h>

wirelessDevice::wirelessDevice(){
    virtualSerial = new SoftwareSerial(7,8); //virtual serial is used for LTE module communication
}
void wirelessDevice::connectToBroker(){

  virtualSerial->println("AT+CMQTTSTART"); 
  delay(200); 
  virtualSerial->println("AT+CMQTTACCQ=0,\"andrija\",0"); 
  delay(200);
  virtualSerial->println("AT+CMQTTCONNECT=0,\"tcp://116.203.35.126:1883\",90,1");
  delay(200);
}

void wirelessDevice::connectCellularDevice(){
  digitalWrite(12, HIGH);
  delay(16000);
  connectToBroker();
  digitalWrite(12, LOW);
}

void wirelessDevice::publishData(String topic1, int value1){
  virtualSerial->println("AT+CMQTTTOPIC=0,8"); 
  delay(5);
  virtualSerial->println("frt/data");
  delay(5);
  virtualSerial->println("AT+CMQTTPAYLOAD=0,16");
  delay(5);
  virtualSerial->println(String("2222222222222222"));
  delay(5);
  virtualSerial->println("AT+CMQTTPUB=0,1,60");
  delay(100);
}