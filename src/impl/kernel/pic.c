#include "pic.h"

// Función para escribir un byte en un puerto de E/S
void outb(uint16_t port, uint8_t data) {
    asm volatile (
        "outb %0, %1"
        :
        : "a" (data), "Nd" (port)
    );
}

// Inicializar el controlador de interrupciones PIC
void init_pic() {
    // Enviar comandos de inicialización
    outb(PIC1_COMMAND, 0x11); // Iniciar inicialización para PIC 1
    outb(PIC2_COMMAND, 0x11); // Iniciar inicialización para PIC 2

    // Especificar offsets de vectores de interrupción
    outb(PIC1_DATA, 0x20); // Offset para las interrupciones IRQ 0-7
    outb(PIC2_DATA, 0x28); // Offset para las interrupciones IRQ 8-15

    // Conectar los PICs
    outb(PIC1_DATA, 0x04); // PIC 1 está conectado al PIC 2 en la línea 2
    outb(PIC2_DATA, 0x02); // PIC 2 está conectado al PIC 1 en la línea 1

    // Habilitar modo 8086/88 (modo de interrupción real)
    outb(PIC1_DATA, 0x01);
    outb(PIC2_DATA, 0x01);

    // Deshabilitar todas las interrupciones
    outb(PIC1_DATA, 0x00);
    outb(PIC2_DATA, 0x00);
}

