#include <mqttClient.h>

wirelessDevice::wirelessDevice(){
    virtualSerial = new SoftwareSerial(7,8); //virtual serial is used for LTE module communication
}
void wirelessDevice::connectToBroker(){

virtualSerial->println("ATE0");
  delay(200);
  virtualSerial->println("AT+CMQTTSTART"); //Establishing MQTT Connection
  delay(200); 
  virtualSerial->println("AT+CMQTTACCQ=0,\"andrija\",1"); //Client ID - change this for each client as this need to be unique
  delay(200);
  virtualSerial->println("AT+CMQTTCONNECT=0,\"tcp://test.mosquitto.org:8883\",90,1"); //MQTT Server Name for connecting this client
  delay(200);
}

void wirelessDevice::connectCellularDevice(){
  digitalWrite(12, HIGH);
  delay(16000);
  connectToBroker();
  digitalWrite(12, LOW);
}

void wirelessDevice::publishData(String topic1, int value1, String topic2, int value2){
  virtualSerial->println("AT+CMQTTTOPIC=0,3"); 
  delay(10);
  virtualSerial->println(topic1);
  delay(10);
  virtualSerial->println("AT+CMQTTPAYLOAD=0,3");
  delay(10);
  virtualSerial->println(String(value1));
  delay(10);
  virtualSerial->println("AT+CMQTTPUB=0,1,60");
  delay(100);

  virtualSerial->println("AT+CMQTTTOPIC=0,3"); 
  delay(10);
  virtualSerial->println(topic2);
  delay(10);
  virtualSerial->println("AT+CMQTTPAYLOAD=0,3");
  delay(10);
  virtualSerial->println(String(value2));
  delay(10);
  virtualSerial->println("AT+CMQTTPUB=0,1,60");
  delay(100);

}