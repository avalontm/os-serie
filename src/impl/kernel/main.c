#include <stdint.h>
#include <stdbool.h>
#include "print.h"
#include "pic.h"
#include "pit.h"
#include "io.h"


// Función para convertir un número entero en una cadena de caracteres
void int_to_str(int num, char* buffer) {
    // Manejar el caso de 0
    if (num == 0) {
        buffer[0] = '0';
        buffer[1] = '\0';
        return;
    }

    bool is_negative = false;
    int i = 0;

    // Manejar números negativos
    if (num < 0) {
        is_negative = true;
        num = -num;
    }

    // Convertir el número en una cadena (en orden inverso)
    while (num > 0) {
        buffer[i++] = num % 10 + '0';
        num /= 10;
    }

    // Agregar el signo negativo si es necesario
    if (is_negative) {
        buffer[i++] = '-';
    }

    // Invertir la cadena para que quede en el orden correcto
    for (int j = 0; j < i / 2; j++) {
        char temp = buffer[j];
        buffer[j] = buffer[i - j - 1];
        buffer[i - j - 1] = temp;
    }

    buffer[i] = '\0'; // Agregar el terminador nulo
}


// Punto de entrada del kernel
void kernel_main() {
    print_clear();
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    print_str("Welcome to our 64-bit kernel!\n");

    char result[20]; // Suficientemente grande para almacenar la cadena resultante

    print_str("[CPU] ");
    int_to_str(get_cpus(), result);
    print_str(result);
    print_str("\n");

    while (1)  // Bucle infinito del kernel
    {
        // Realizar otras tareas del kernel
    }
}
