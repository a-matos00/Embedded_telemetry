#include "mcp_can.h"
#include "mcp_can_dfs.h"
#include <SPI.h>
   
void initCANDevice();
void displayRxMessage();
void recieveMessages();
void readData(long unsigned int, unsigned char*);