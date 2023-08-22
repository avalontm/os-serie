#include <allocator.h>

// Inicialización del allocator
void init_allocator(void* memory, size_t size) {
    memory_start = memory;

    // Crear un bloque inicial con todo el espacio disponible
    Block* initial_block = (Block*)memory;
    initial_block->size = size - sizeof(Block);
    initial_block->next = NULL;
}

// Función para asignar memoria
void* allocate(size_t size) {
    if (!memory_start) {
        // El allocator no se ha inicializado
        return NULL;
    }

    Block* current_block = (Block*)memory_start;
    Block* prev_block = NULL;

    while (current_block) {
        if (current_block->size >= size) {
            if (current_block->size > size + sizeof(Block)) {
                // Si hay suficiente espacio para dividir el bloque
                Block* new_block = (Block*)((char*)current_block + sizeof(Block) + size);
                new_block->size = current_block->size - size - sizeof(Block);
                new_block->next = current_block->next;
                current_block->size = size;
                current_block->next = new_block;
            }

            return (char*)current_block + sizeof(Block);
        }

        prev_block = current_block;
        current_block = current_block->next;
    }

    return NULL; // No se encontró espacio suficiente
}

// Función para liberar memoria
void deallocate(void* ptr) {
    if (!memory_start || !ptr) {
        return; // El allocator no se ha inicializado o el puntero es nulo
    }

    Block* current_block = (Block*)((char*)ptr - sizeof(Block));
    current_block->next = NULL; // Marcar el bloque como libre
}
