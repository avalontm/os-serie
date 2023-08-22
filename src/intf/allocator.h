#include <stddef.h>

// Definición de una estructura para un bloque de memoria
typedef struct Block {
    size_t size;
    struct Block* next;
} Block;

// Puntero al inicio de la memoria disponible
static void* memory_start = NULL;
void init_allocator(void* memory, size_t size);
void* allocate(size_t size);
void deallocate(void* ptr);