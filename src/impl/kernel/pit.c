#include <stdint.h>
#include "pic.h"
#include "io.h"

// Función para configurar el temporizador del sistema (PIT)
void init_timer() {
    // Frecuencia del temporizador en Hz (por ejemplo, 100 Hz)
    uint16_t frequency = 100;

    // Calcular el valor divisor para establecer la frecuencia deseada
    uint16_t divisor = 1193180 / frequency;

    // Enviar los bytes de configuración al controlador PIT
    outb(0x43, 0x36); // Enviar el byte de configuración al controlador PIT
    outb(0x40, divisor & 0xFF); // Enviar el byte bajo del divisor
    outb(0x40, (divisor >> 8) & 0xFF); // Enviar el byte alto del divisor
}