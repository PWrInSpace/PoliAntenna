#include <stdio.h>
#include <driver/i2c.h>
#include "esp_log.h"
#include "mmc59830ma.h"
#define TAG "I2C"

bool mag_reset()
{
    uint8_t cmd = 0x10;
    if(!I2C_master_write(I2C_NUM_0,0x30,0x09,&cmd,1)){
    
    ESP_LOGE(TAG,"I2C Master restart (MAG)");
    return false;
    }
    vTaskDelay(1/portTICK_PERIOD_MS);
    return true;
}
bool get_mag_data(mag_data_s *data){
        uint8_t cmd = 0x01;
        uint8_t date[6];
        if(!I2C_master_write(I2C_NUM_0,0x30,0x09,&cmd,1)){
            ESP_LOGE(TAG,"I2C Master write error (MAG)");
            return false;
        }
        vTaskDelay(10/portTICK_PERIOD_MS);
        if(!I2C_master_read(I2C_NUM_0,0x30,0x00,date,6)){
            ESP_LOGE(TAG,"I2C Master read error (MAG)");
            return false;
        }

        float x = 0;
        uint16_t resultx = 0; 
        resultx |= date[1];
        resultx |= (date[0] << 8);
        x = (float)(resultx - 32768.0);
        x = x / 4096.0;
        
        

        float y = 0;
        uint16_t resulty = 0;
        resulty |= date[3];
        resulty |= (date[2] << 8);
        y = (float)(resulty - 32768.0);
        y = y / 4096.0;

        

        float z = 0;
        uint16_t resultz = 0;
        resultz |= date[5];
        resultz |= (date[4] << 8);
        z = (float)(resultz - 32768.0);
        z = z / 4096.0;

        data->x = x;
        data->y = y;
        data->z = z;
        

        return true;

}

    




