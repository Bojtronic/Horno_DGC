# 🔥 Sistema de Automatización para Horno Eléctrico

El sistema ha sido desarrollado utilizando **ESP32, diseño de PCB en KiCad y una interfaz web**, permitiendo la **supervisión de sensores y control de actuadores en tiempo real**.

Este documento describe paso a paso cómo configurar el entorno de desarrollo, entender la arquitectura del sistema y ejecutar la aplicación.

El proyecto se encuentra en una etapa inicial y toma como referencia el Trabajo Final de Graduación (TFG) de Manuel Bojorge.

---

## 📦 Requisitos

### Hardware
- **ESP32**
- PCB diseñado en **KiCad**
- Sensores:
  - Temperatura
  - Corriente
  - Señales analógicas (voltaje DC variable)
- Actuadores:
  - Relés (contactos secos)
  - Etapa de potencia con IGBT (PWM)

---

### Software

#### 🔹 Arduino IDE
Entorno para programar el ESP32.

Verificar instalación:
```bash
arduino --version
```

Descarga: https://www.arduino.cc/en/software

---

#### 🔹 KiCad
Software para diseño de esquemas y PCB.

Descarga: https://www.kicad.org/

---

#### 🔹 Visual Studio Code
Editor recomendado para:
- Edición de código
- Control de versiones
- Manejo del proyecto

Descarga: https://code.visualstudio.com/

---

#### 🔹 Git (opcional)
Para control de versiones.

Verificar:
```bash
git --version
```

Descarga: https://git-scm.com/

---

### Sistema Operativo
- **Windows 10 / 11** (recomendado)

---

## 📥 1. Estructura del Proyecto

El proyecto se divide en tres componentes principales:

| Componente | Descripción |
|----------|------------|
| Hardware (PCB) | Diseño electrónico en KiCad |
| Firmware (ESP32) | Control de entradas y salidas |
| Interfaz Web | Visualización y control remoto |

---

## 🧩 2. Diseño del Hardware (PCB)

El diseño del PCB se realiza en **KiCad** e incluye:

### 🔹 Entradas digitales
- Tipo: **contacto seco**
- Conversión a nivel lógico:
  - **3.3V → 1 lógico**
  - **< 1.7V → 0 lógico**

Permiten detectar:
- Estados ON/OFF externos
- Sensores digitales

---

### 🔹 Entradas analógicas
- Señales de **voltaje DC variable**
- Usadas para:
  - Sensores de temperatura
  - Sensores de corriente
  - Otras variables físicas

---

### 🔹 Salidas digitales (Relés)
- Control de **contactos secos**
- Permiten manejar:
  - **120 VAC**
  - **240 VAC**

Aplicaciones:
- Encendido/apagado del horno
- Control de resistencias
- Activación de sistemas auxiliares

---

### 🔹 Salidas analógicas (voltaje variable)
- Rango:
  - **0V – 3.3V DC (ESP32)**
- Amplificación:
  - Hasta **12V DC**

Estas señales se exponen en terminales del PCB para controlar:
- Drivers externos
- Módulos de potencia

---

### 🔹 Control PWM con IGBT
- Generación de señal **PWM desde el ESP32**
- Etapa de potencia:
  - Driver de **IGBT**
- Permite:
  - Control fino de potencia del horno
  - Regulación de temperatura

---

## 🧠 3. Arquitectura del Sistema

El sistema funciona bajo el siguiente flujo:

1. La **interfaz web** envía comandos
2. El **ESP32 recibe las solicitudes**
3. El microcontrolador:
   - Procesa entradas
   - Controla salidas
4. Se actualizan los valores en la interfaz

---

## 🌐 4. Interfaz Web

La aplicación web permite:

### 🔹 Monitoreo
- Temperatura
- Corriente
- Voltajes
- Estados digitales

---

### 🔹 Control
- Activación/desactivación de relés
- Control de salidas analógicas
- Ajuste de parámetros de operación

---

### 🔹 Comunicación
- La interfaz envía comandos al ESP32
- El ESP32 responde con datos en tiempo real

---

## ⚙️ 5. Programación del ESP32

Abrir el proyecto en **Arduino IDE**

Seleccionar:
- Placa: ESP32
- Puerto correspondiente

Compilar y cargar:

```bash
Upload
```

El firmware se encarga de:

- Leer entradas digitales y analógicas
- Generar señales PWM
- Controlar relés
- Comunicarse con la interfaz web

---

## ▶️ 6. Ejecución del Sistema

1. Energizar el PCB
2. Conectar el ESP32 a la red
3. Acceder a la interfaz web (según configuración de red)

Desde la interfaz se puede:

- Ver datos en tiempo real
- Controlar el horno
- Ajustar parámetros

---

## 🏗 7. Flujo de Desarrollo

### 🔹 Hardware
- Diseño esquemático en KiCad
- Diseño de PCB
- Fabricación y pruebas

---

### 🔹 Firmware
- Desarrollo en Arduino IDE
- Pruebas de entradas/salidas
- Integración con hardware

---

### 🔹 Software
- Desarrollo de interfaz web
- Integración con ESP32
- Pruebas de comunicación

---

## 🛡 Reglas importantes

- ❌ No conectar cargas AC sin aislamiento adecuado
- ❌ No exceder voltajes de entrada del ESP32 (3.3V)
- ❌ Verificar conexiones antes de energizar

- ⚠ Manejar con precaución:
  - 120 VAC / 240 VAC
  - Etapas de potencia con IGBT

---

## 🚧 Estado del proyecto

- ✔ Diseño conceptual
- ✔ Definición de arquitectura
- ⚠ En desarrollo:
  - PCB
  - Firmware
  - Interfaz web

---

## 📌 Notas adicionales

Este proyecto toma como base el **TFG de Manuel Bojorge**, el cual sirve como referencia para:

- Arquitectura del sistema
- Diseño electrónico
- Integración hardware–software

---

## 📧 Soporte

Correo: **bojtronic@gmail.com**
