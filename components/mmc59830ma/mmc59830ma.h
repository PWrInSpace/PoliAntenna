#ifndef MMC59830MA_H
#define MMC59830MA_H

#include <stdio.h>
#include <driver/i2c.h>
#include "esp_log.h"
#include <math.h>
#include <i2c.h>
#include <esp_log.h>

#define TAG "I2C"

typedef struct {
    float x;
    float y;
    float z;
} mag_data_s;

bool mag_reset();
bool get_mag_data(mag_data_s *data);



#endif

