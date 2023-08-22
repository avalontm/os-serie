#include <stdint.h>

// Definir puertos de comandos y datos del controlador PIC
#define PIC1_COMMAND 0x20
#define PIC1_DATA    0x21
#define PIC2_COMMAND 0xA0
#define PIC2_DATA    0xA1

void init_pic();
void enable_interrupts();
void clean_interrupts();
int get_cpus();