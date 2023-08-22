#include "pic.h"
#include "io.h"

// Función para habilitar las interrupciones
void enable_interrupts() {
    asm("sti"); // Set Interrupt flag
}

// Función para limpiar la interrupción en el controlador de interrupciones (PIC)
void clean_interrupts() {
    outb(0x20, 0x20);
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


int get_cpus()
{
unsigned int num_cpus;

    // Código para obtener el número de CPUs
    asm (
        "mov $11, %%eax\n\t"  // Código de función 11 (Obtener información del sistema)
        "mov $0, %%ecx\n\t"   // Subfunción 0 (Obtener número de CPUs)
        "int $0x15\n\t"       // Llamar a la interrupción 0x15
        "mov %%ebx, %0\n\t"   // Almacenar el resultado en num_cpus
        : "=r" (num_cpus)     // Salida
        :                    // Entradas
        : "eax", "ebx", "ecx" // Registros que se modifican
    );

    return num_cpus;
}