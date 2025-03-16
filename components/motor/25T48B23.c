#include "25T48B23.h"

void step_motor_init()
{
        ESP_LOGI(TAG, "MOTOR INIT");
}
void step_motor_step(int steps)
{
        ESP_LOGI(TAG, "MOTOR STEP");

        if (steps < 0)
        {
            ESP_LOGI(TAG, "STEP MOTOR BACKWARD");
            //Tu bedzie zmiana kierunku obrotu silnika
        }
        else
        {
            ESP_LOGI(TAG, "STEP MOTOR FORWARD");
            //Tu bedzie zmiana kierunku obrotu silnika
        }

        for (int i = 0; i < abs(steps); i++)
        {
                ESP_LOGI(TAG, "STEP MOTOR STEP");
                step_motor_angle += MOTOR_STEP;
                //Tu bedzie krok silnika tyle razy ile trzeba
        }
        ESP_LOGI(TAG, "STEP MOTOR ANGLE: %d", step_motor_angle);
}