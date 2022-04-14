#include "mcp_can.h"
#include "mcp_can_dfs.h"
#include <SPI.h>
#include "data.h"

class canHandler{

public:
    canHandler(uint8_t int_pin, uint8_t CS_pin);
    void initCANDevice();
    void displayRxMessage();
    void recieveMessages();
    void readData(long unsigned int, unsigned char*);

MCP_CAN* CAN_DEVICE;
uint8_t m_INT_pin;
Data* rpm;
long unsigned int message_id;
unsigned char DLC;
unsigned char rxBuf[8];
char msgString[128];
};
