#include <Arduino.h>

#include "config.h"

//==================================================
// TESTS
//==================================================

#include "test_entradas.h"
#include "test_salidas.h"
#include "test_temperatura.h"


//==================================================
// SETUP
//==================================================

void setup()
{
    DEVICE_SERIAL.begin(115200);

    delay(500);

    DEVICE_SERIAL.println();
    DEVICE_SERIAL.println("========================================");
    DEVICE_SERIAL.println("       SISTEMA DE PRUEBAS ESP32");
    DEVICE_SERIAL.println("========================================");
    DEVICE_SERIAL.println();


    //==================================================
    // SELECCIONAR TEST
    //==================================================

    // TEST DE ENTRADAS
    // Descomentar para probar entradas digitales
    //
    // Entrada 1 -> Relé 1
    // Entrada 2 -> Relé 2
    // Entrada 3 -> Relé 3
    // Entrada 4 -> Relé 4

    //testEntradasInit();


    // TEST DE SALIDAS
    // Descomentar para probar los 6 relés
    //
    // Cada salida permanece activa 3 segundos.
    // Después de la salida 6:
    // todas las salidas permanecen activas 10 segundos.
    //
    testSalidasInit();


    // TEST DE TEMPERATURA
    // Descomentar para probar los 3 MAX31855
    //
    //testTemperaturaInit();
}


//==================================================
// LOOP
//==================================================

void loop()
{
    //==================================================
    // TEST DE ENTRADAS
    //==================================================

    //testEntradasUpdate();


    //==================================================
    // TEST DE SALIDAS
    //==================================================

    testSalidasUpdate();


    //==================================================
    // TEST DE TEMPERATURA
    //==================================================

    //testTemperaturaUpdate();
}
