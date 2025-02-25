// Copyright 2022 PWrInSpace, Kuba
#ifndef I2C_SIMPLE
#define I2C_SIMPLE

#include "driver/i2c.h"

#define CONFIG_SDA_SEN 22
#define CONFIG_SCL_SEN 21
#define CONFIG_SDA_COM 22
#define CONFIG_SCL_COM 21

typedef i2c_config_t i2c_t;


bool I2C_master_init(i2c_t *i2c, i2c_port_t port, uint8_t sda, uint8_t scl, uint32_t freq_hz);
bool I2C_master_write(i2c_port_t port, uint8_t dev_addr, uint8_t reg_addr, const uint8_t *data,
                        size_t len);
bool I2C_master_read(i2c_port_t port, uint8_t dev_addr, uint8_t reg_addr, uint8_t *data,
                        size_t len);

bool i2c_sensors_init(void);
bool i2c_com_init(void);
bool i2c_com_only_read(uint8_t dev_addr, uint8_t *data, size_t len);
bool i2c_sensors_read(uint8_t dev_addr, uint8_t reg_addr, uint8_t *data, size_t len);
bool i2c_sensors_write(uint8_t dev_addr, uint8_t reg_addr, const uint8_t *data, size_t len);
bool i2c_com_read(uint8_t dev_addr, uint8_t reg_addr, uint8_t *data, size_t len);
bool i2c_com_write(uint8_t dev_addr, uint8_t reg_addr, uint8_t *data, size_t len);


#endif
