#ifndef I2C_H
#define I2C_H
#include "API.h"
// 7-bit address of the slave I2C device, right aligned
#define I2C_SLAVE_ADDR         0x4A
// Ficitonal "enable" register for the device
#define I2C_SLAVE_REG_ENABLE   0x38
// Fictional 32-bit "parameters" buffer for the device, 0x6D-0x6F
#define I2C_SLAVE_BUF_PARAMS   0x6D

// 7-bit address of the slave I2C device, right aligned
#define I2C_SLAVE_ADDR       0x4A
// Fictional 32-bit data buffer for the device, 0x30-0x34
#define I2C_SLAVE_BUF_DATA   0x30
class i2c{
private:
  uint8_t data_in[4];
  int32_t reading;
public:
  i2c();
  void read();

  uint8_t* getData();
};
#endif
