#include <stdio.h>
#include <esp_log.h>
#include <i2c.h>
#include <bmi08_wrapper.h>
#include <mmc59830ma.h>

#define TAG "MAIN"
#define ACC_TAG "ACC"
#define GYRO_TAG "GYRO"


// nie działa softrestart akcelerometru, przez to że nie ma po nim delaya 
// TODO: dodać delay po softrestart -- done
// TODO: iść biegać teraz, bo muszę być gotowy na poznań, a narazie nie jestem -- done w połowie

// tyle ile da się wyliczyć z imu działa, twoja kolej Bartek ;)
void app_main(void)
{
    if (!i2c_sensors_init()) {
        ESP_LOGE(TAG, "Sensors init failed");
        return;
    }

    if (!bmi08_wrapper_init()) {
        ESP_LOGE(TAG, "BMI08 init failed");
        return;
    }

    if (!mag_reset()) {
        ESP_LOGE(TAG, "MAG reset failed");
        return;
    }
    float geo_dir;
    orientation_t orientation;
    mag_data_s mag_data;

    while(1) 
    {
        ESP_LOGI(TAG, "DZIALAM");
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}