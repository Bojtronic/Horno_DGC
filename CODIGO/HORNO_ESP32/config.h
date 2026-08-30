#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
#include <Adafruit_MAX31855.h>

//==================================================
//                CONFIGURACIÓN GENERAL
//==================================================
//
// Hardware:
//
//  - ESP32-WROOM (TTGO)
//  - WiFi habilitado
//  - SPI VSPI
//  - UART0 para comunicación externa
//
//==================================================


//==================================================
//              TERMOCUPLAS MAX31855
//==================================================

constexpr uint8_t CFG_NUM_TEMP_SENSORS = 3;

// SPI VSPI
constexpr uint8_t CFG_MAX_CLK  = 18;
constexpr uint8_t CFG_MAX_MISO = 19;

constexpr uint8_t CFG_MAX_CS[CFG_NUM_TEMP_SENSORS] =
{
    21,
    22,
    23
};


//==================================================
//          ENTRADAS ANALÓGICAS (ADC1)
//==================================================

constexpr uint8_t CFG_NUM_ANALOG_INPUTS = 2;

constexpr uint8_t CFG_ANALOG_INPUTS[CFG_NUM_ANALOG_INPUTS] =
{
    32,
    33
};


//==================================================
//            ENTRADAS DIGITALES
//==================================================

constexpr uint8_t CFG_NUM_DIGITAL_INPUTS = 4;

constexpr uint8_t CFG_DIGITAL_INPUTS[CFG_NUM_DIGITAL_INPUTS] =
{
    34,
    35,
    36,
    39
};


//==================================================
//             SALIDAS ANALÓGICAS
//==================================================

constexpr uint8_t CFG_NUM_ANALOG_OUTPUTS = 2;

constexpr uint8_t CFG_ANALOG_OUTPUTS[CFG_NUM_ANALOG_OUTPUTS] =
{
    25,
    26
};


//==================================================
//                    RELÉS
//==================================================

constexpr uint8_t CFG_NUM_RELAYS = 6;

constexpr uint8_t CFG_RELAYS[CFG_NUM_RELAYS] =
{
    2,
    4,
    5,
    12,
    13,
    14
};


//==================================================
//                 DRIVERS IGBT
//==================================================

constexpr uint8_t CFG_NUM_IGBT = 2;

constexpr uint8_t CFG_IGBTS[CFG_NUM_IGBT] =
{
    16,
    17
};


//==================================================
//             UART0 (COMUNICACIÓN)
//==================================================
//
// UART Hardware 0
//
// TX -> GPIO1
// RX -> GPIO3
//
//==================================================

#define DEVICE_SERIAL Serial

constexpr uint8_t CFG_UART_TX = 1;
constexpr uint8_t CFG_UART_RX = 3;


//==================================================
//              GPIO DISPONIBLES
//==================================================

constexpr uint8_t CFG_FREE_GPIO = 27;

#endif