#include "test_entradas.h"

void testEntradasInit()
{
    // Configurar entradas digitales
    for (uint8_t i = 0; i < CFG_NUM_DIGITAL_INPUTS; i++)
    {
        pinMode(CFG_DIGITAL_INPUTS[i], INPUT);
    }

    // Configurar todas las salidas
    for (uint8_t i = 0; i < CFG_NUM_RELAYS; i++)
    {
        pinMode(CFG_RELAYS[i], OUTPUT);

        // Todas las salidas inicialmente apagadas
        digitalWrite(CFG_RELAYS[i], LOW);
    }

    DEVICE_SERIAL.println();
    DEVICE_SERIAL.println("====================================");
    DEVICE_SERIAL.println("     TEST DE ENTRADAS DIGITALES");
    DEVICE_SERIAL.println("====================================");

    DEVICE_SERIAL.println("Entrada 1 -> Salida 1");
    DEVICE_SERIAL.println("Entrada 2 -> Salida 2");
    DEVICE_SERIAL.println("Entrada 3 -> Salida 3");
    DEVICE_SERIAL.println("Entrada 4 -> Salida 4");
    DEVICE_SERIAL.println();
}


void testEntradasUpdate()
{
    // Solo se utilizan las primeras 4 entradas
    // y las primeras 4 salidas.

    for (uint8_t i = 0; i < CFG_NUM_DIGITAL_INPUTS; i++)
    {
        int estadoEntrada = digitalRead(CFG_DIGITAL_INPUTS[i]);

        if (estadoEntrada == LOW)
        {
            digitalWrite(CFG_RELAYS[i], HIGH);
        }
        else
        {
            digitalWrite(CFG_RELAYS[i], LOW);
        }
    }
}
