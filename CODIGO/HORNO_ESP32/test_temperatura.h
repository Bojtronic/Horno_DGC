#ifndef TEST_TEMPERATURA_H
#define TEST_TEMPERATURA_H

#include <Arduino.h>
#include "config.h"
#include <Adafruit_MAX31855.h>

// Inicializa los sensores de temperatura
void testTemperaturaInit();

// Lee y muestra las temperaturas
void testTemperaturaUpdate();

#endif
