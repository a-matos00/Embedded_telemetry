#include<data.h>

Data::Data(){}

Data::Data(String name, uint8_t index, uint8_t size, uint8_t factor, uint8_t offset)
{
    this->m_index = index;
    this->m_size = size;
    this->m_factor = factor;
    this->m_offset = offset;
    this->m_name = name;
}
void Data::getValue(unsigned char* data)
{
    switch(m_size){
        case 1: m_value = (data[m_index] * m_factor) - m_offset; break;
        case 2:m_value = (data[m_index] * 256 + data[m_index + 1]) * m_factor - m_offset; break;
    }
}