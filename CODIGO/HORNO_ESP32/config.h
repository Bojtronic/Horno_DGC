#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
#include <Adafruit_MAX31855.h>

//==================================================
//                CONFIGURACIÓN GENERAL
//==================================================
//
// Hardware:
//  - ESP32-WROOM (TTGO)
//  - WiFi habilitado
//  - SPI VSPI
//  - UART0 para comunicación externa
//
// NOTA:
//
// UART0 comparte los pines utilizados durante la
// programación.
//
// Antes de cargar un nuevo firmware se recomienda
// desconectar el dispositivo conectado a UART0.
//
//==================================================


//==================================================
//              TERMOCUPLAS MAX31855
//==================================================

constexpr uint8_t NUM_TEMP_SENSORS = 3;

// SPI VSPI

constexpr uint8_t MAX_CLK  = 18;
constexpr uint8_t MAX_MISO = 19;

constexpr uint8_t MAX_CS[NUM_TEMP_SENSORS] =
{
    21,
    22,
    23
};


//==================================================
//          ENTRADAS ANALÓGICAS (ADC1)
//==================================================

constexpr uint8_t NUM_ANALOG_INPUTS = 2;

constexpr uint8_t ANALOG_INPUTS[NUM_ANALOG_INPUTS] =
{
    32,
    33
};

// GPIO ADC1 disponibles
//
// 34
// 35


//==================================================
//            ENTRADAS DIGITALES
//==================================================

constexpr uint8_t NUM_DIGITAL_INPUTS = 4;

constexpr uint8_t DIGITAL_INPUTS[NUM_DIGITAL_INPUTS] =
{
    34,
    35,
    36,
    39
};


//==================================================
//             SALIDAS ANALÓGICAS
//==================================================

constexpr uint8_t NUM_ANALOG_OUTPUTS = 2;

constexpr uint8_t ANALOG_OUTPUTS[NUM_ANALOG_OUTPUTS] =
{
    25,
    26
};


//==================================================
//                 RELÉS
//==================================================

constexpr uint8_t NUM_RELAYS = 6;

constexpr uint8_t RELAYS[NUM_RELAYS] =
{
    2,
    4,
    5,
    12,
    13,
    14
};


//==================================================
//              DRIVERS IGBT
//==================================================

constexpr uint8_t NUM_IGBT = 2;

constexpr uint8_t IGBTS[NUM_IGBT] =
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
// Durante el funcionamiento:
//
//      ESP32 <-------> Arduino
//      ESP32 <-------> PLC
//      ESP32 <-------> Otro ESP32
//
// Antes de programar:
//
// 1) Desconectar el dispositivo externo.
// 2) Conectar USB.
// 3) Cargar firmware.
// 4) Reconectar UART.
//

#define DEVICE_SERIAL Serial

constexpr uint8_t UART_TX = 1;
constexpr uint8_t UART_RX = 3;


//==================================================
//          GPIO DISPONIBLES
//==================================================

//
// GPIO0  -> BOOT (evitar)
//
// GPIO27 -> Libre para futuras ampliaciones.
//

constexpr uint8_t FREE_GPIO = 27;

#endif
