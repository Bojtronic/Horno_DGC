#include "test_salidas.h"

//==================================================
// CONFIGURACIÓN DEL TEST
//==================================================

constexpr unsigned long TIEMPO_SALIDA = 3000;
constexpr unsigned long TIEMPO_TODAS  = 10000;


//==================================================
// ESTADOS DEL TEST
//==================================================

enum EstadoTestSalidas
{
    ACTIVAR_SALIDA,
    TODAS_ACTIVADAS
};


//==================================================
// VARIABLES INTERNAS
//==================================================

static EstadoTestSalidas estado = ACTIVAR_SALIDA;

static uint8_t salidaActual = 0;

static unsigned long tiempoInicio = 0;


//==================================================
// FUNCIONES INTERNAS
//==================================================

static void apagarTodasLasSalidas()
{
    for (uint8_t i = 0; i < CFG_NUM_RELAYS; i++)
    {
        digitalWrite(CFG_RELAYS[i], LOW);
    }
}


static void activarTodasLasSalidas()
{
    for (uint8_t i = 0; i < CFG_NUM_RELAYS; i++)
    {
        digitalWrite(CFG_RELAYS[i], HIGH);
    }
}


static void activarSalida(uint8_t indice)
{
    apagarTodasLasSalidas();

    if (indice < CFG_NUM_RELAYS)
    {
        digitalWrite(CFG_RELAYS[indice], HIGH);
    }
}


//==================================================
// INICIALIZACIÓN
//==================================================

void testSalidasInit()
{
    DEVICE_SERIAL.println();
    DEVICE_SERIAL.println("====================================");
    DEVICE_SERIAL.println("       TEST DE SALIDAS / RELES");
    DEVICE_SERIAL.println("====================================");

    // Configurar salidas
    for (uint8_t i = 0; i < CFG_NUM_RELAYS; i++)
    {
        pinMode(CFG_RELAYS[i], OUTPUT);
    }

    // Apagar todas
    apagarTodasLasSalidas();

    // Comenzar con salida 1
    salidaActual = 0;

    activarSalida(salidaActual);

    tiempoInicio = millis();

    DEVICE_SERIAL.println("Salida 1 ACTIVADA");
}


//==================================================
// ACTUALIZACIÓN
//==================================================

void testSalidasUpdate()
{
    unsigned long ahora = millis();

    switch (estado)
    {
        //--------------------------------------------------
        // ACTIVAR SALIDAS UNA POR UNA
        //--------------------------------------------------

        case ACTIVAR_SALIDA:

            if (ahora - tiempoInicio >= TIEMPO_SALIDA)
            {
                // Apagar salida actual
                digitalWrite(CFG_RELAYS[salidaActual], LOW);

                DEVICE_SERIAL.print("Salida ");
                DEVICE_SERIAL.print(salidaActual + 1);
                DEVICE_SERIAL.println(" DESACTIVADA");

                //--------------------------------------------------
                // ¿ERA LA SALIDA 6?
                //--------------------------------------------------

                if (salidaActual >= CFG_NUM_RELAYS - 1)
                {
                    // Pasar a etapa de todas las salidas
                    activarTodasLasSalidas();

                    DEVICE_SERIAL.println();
                    DEVICE_SERIAL.println("TODAS LAS SALIDAS ACTIVADAS");
                    DEVICE_SERIAL.println("Manteniendo durante 10 segundos...");

                    estado = TODAS_ACTIVADAS;
                    tiempoInicio = ahora;
                }
                else
                {
                    // Siguiente salida
                    salidaActual++;

                    activarSalida(salidaActual);

                    DEVICE_SERIAL.print("Salida ");
                    DEVICE_SERIAL.print(salidaActual + 1);
                    DEVICE_SERIAL.println(" ACTIVADA");

                    tiempoInicio = ahora;
                }
            }

            break;


        //--------------------------------------------------
        // TODAS LAS SALIDAS ACTIVADAS
        //--------------------------------------------------

        case TODAS_ACTIVADAS:

            if (ahora - tiempoInicio >= TIEMPO_TODAS)
            {
                apagarTodasLasSalidas();

                DEVICE_SERIAL.println("TODAS LAS SALIDAS DESACTIVADAS");
                DEVICE_SERIAL.println();
                DEVICE_SERIAL.println("Reiniciando ciclo...");
                DEVICE_SERIAL.println();

                // Volver a salida 1
                salidaActual = 0;

                activarSalida(salidaActual);

                DEVICE_SERIAL.println("Salida 1 ACTIVADA");

                estado = ACTIVAR_SALIDA;

                tiempoInicio = ahora;
            }

            break;
    }
}
