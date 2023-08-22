#include <stdint.h>

// Función para escribir un byte en un puerto de E/S
void outb(uint16_t port, uint8_t data) {
    asm (
        "outb %0, %1"
        :
        : "a" (data), "Nd" (port)
    );
}

// Función para leer un byte de un puerto de E/S
uint8_t inb(uint16_t port) {
    uint8_t data;
    asm (
        "inb %1, %0"
        : "=a" (data)
        : "Nd" (port)
    );
    return data;
}
