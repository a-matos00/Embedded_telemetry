#include <Arduino.h>

enum CAN_ID{
    RPM_ID = 0x123,  
};

class Data{
    public:
       uint32_t m_value = 0;
       uint8_t m_index = 0;
       uint8_t m_size = 0;
       uint8_t m_factor = 0;
       uint8_t m_offset = 0;
       String m_name;

    Data();
       Data(String name, uint8_t index, uint8_t size, uint8_t factor, uint8_t offset);
       void getValue(unsigned char*);
};
