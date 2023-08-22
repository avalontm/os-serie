#include "print.h"
#include "pic.h"


// Punto de entrada del kernel
void kernel_main() {
    print_clear();
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    print_str("Iniciando interrupciones\n");

    init_pic();
    
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    print_str("Welcome to our 64-bit kernel!\n");

      // Bucle infinito del kernel
    while (1) {
        // Realizar otras tareas del kernel
    }
}
