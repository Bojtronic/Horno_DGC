#include "test_temperatura.h"

//==================================================
// MAX31855
//==================================================

// Sensor 1
Adafruit_MAX31855 max31855_1(
    CFG_MAX_CLK,
    CFG_MAX_CS[0],
    CFG_MAX_MISO
);

// Sensor 2
Adafruit_MAX31855 max31855_2(
    CFG_MAX_CLK,
    CFG_MAX_CS[1],
    CFG_MAX_MISO
);

// Sensor 3
Adafruit_MAX31855 max31855_3(
    CFG_MAX_CLK,
    CFG_MAX_CS[2],
    CFG_MAX_MISO
);


// Arreglo de punteros para acceder a los 3 sensores
Adafruit_MAX31855* sensores[CFG_NUM_TEMP_SENSORS] =
{
    &max31855_1,
    &max31855_2,
    &max31855_3
};


//==================================================
// CONFIGURACIÓN DE LECTURA
//==================================================

constexpr unsigned long INTERVALO_LECTURA = 1000;

static unsigned long ultimaLectura = 0;


//==================================================
// INICIALIZACIÓN
//==================================================

void testTemperaturaInit()
{
    DEVICE_SERIAL.println();
    DEVICE_SERIAL.println("====================================");
    DEVICE_SERIAL.println("       TEST DE TEMPERATURAS");
    DEVICE_SERIAL.println("====================================");

    DEVICE_SERIAL.print("Sensores configurados: ");
    DEVICE_SERIAL.println(CFG_NUM_TEMP_SENSORS);

    DEVICE_SERIAL.print("CLK  : GPIO");
    DEVICE_SERIAL.println(CFG_MAX_CLK);

    DEVICE_SERIAL.print("MISO : GPIO");
    DEVICE_SERIAL.println(CFG_MAX_MISO);

    for (uint8_t i = 0; i < CFG_NUM_TEMP_SENSORS; i++)
    {
        DEVICE_SERIAL.print("Sensor ");
        DEVICE_SERIAL.print(i + 1);
        DEVICE_SERIAL.print(" CS: GPIO");
        DEVICE_SERIAL.println(CFG_MAX_CS[i]);
    }

    DEVICE_SERIAL.println();

    // Inicializar cada MAX31855
    for (uint8_t i = 0; i < CFG_NUM_TEMP_SENSORS; i++)
    {
        if (sensores[i]->begin())
        {
            DEVICE_SERIAL.print("MAX31855 #");
            DEVICE_SERIAL.print(i + 1);
            DEVICE_SERIAL.println(" OK");
        }
        else
        {
            DEVICE_SERIAL.print("ERROR inicializando MAX31855 #");
            DEVICE_SERIAL.println(i + 1);
        }
    }

    DEVICE_SERIAL.println();

    ultimaLectura = 0;
}


//==================================================
// LECTURA DE TEMPERATURAS
//==================================================

void testTemperaturaUpdate()
{
    unsigned long ahora = millis();

    if (ahora - ultimaLectura < INTERVALO_LECTURA)
    {
        return;
    }

    ultimaLectura = ahora;

    DEVICE_SERIAL.println("------------------------------------");

    for (uint8_t i = 0; i < CFG_NUM_TEMP_SENSORS; i++)
    {
        double temperatura = sensores[i]->readCelsius();

        DEVICE_SERIAL.print("Temperatura ");
        DEVICE_SERIAL.print(i + 1);
        DEVICE_SERIAL.print(": ");

        if (isnan(temperatura))
        {
            DEVICE_SERIAL.println("ERROR");

            // Diagnóstico del MAX31855
            uint8_t error = sensores[i]->readError();

            DEVICE_SERIAL.print("  Error MAX31855: 0x");
            DEVICE_SERIAL.println(error, HEX);
        }
        else
        {
            DEVICE_SERIAL.print(temperatura, 2);
            DEVICE_SERIAL.println(" °C");
        }
    }
}
