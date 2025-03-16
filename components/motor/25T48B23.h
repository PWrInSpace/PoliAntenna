
#ifndef MOTOR_25T48B23_H
#define MOTOR_25T48B23_H

#include <stdio.h>
#include <driver/i2c.h>
#include "esp_log.h"
#include <math.h>
#include <i2c.h>
#include <esp_log.h>

#define TAG "STEP_MOTOR"
#define MOTOR_STEP  7.5 / 20.8 * 13 //TODO: zobaczyc czy optymalne dzialania w makro (przekladnia 20.8 : 1 i skok 7.5 stopnia)


volatile int step_motor_angle = 0;

void step_motor_init(); //inicjalizacja ukladu sterujacego silnikiem krokowym (jesli wymagna)
void step_motor_step(int steps); //obrot silnika o zadana liczbe krokow


#endif

// step silnika to 7.5 stopnia a przekladnia 20.8 : 1 wiec 7.5 / 20.8 = 0.3605769230769231

// 0.3605769230769231 to wartość kąta w stopniach na jeden krok silnika
// 0.7211538461538461
// 1.0817307692307692
// 1.4423076923076923
// 1.8028846153846154
// 2.1634615384615383
// 2.5240384615384617
// 2.8846153846153846
// 3.2451923076923075
// 3.605769230769231
// 3.9663461538461537
// 4.326923076923077
// 4.6875 to 13 krokow silnika i ladna wartosc reprezentowana we float
// wiec wstepnie 13 krokow silnika bedzie uzywane do obrotu o 4.6875 stopnia
// jako minimalna wartosc obrotu, dzieki temu wartosci się nie rozjezdzaja