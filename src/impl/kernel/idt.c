#include <stdint.h>
#include "idt.h"
#include "io.h"

// Función para cargar la IDT en la arquitectura x86
void load_idt(struct IDTDescriptor* idt_descriptor) {
    asm volatile (
        "lidt %0"
        :
        : "m" (*idt_descriptor)
    );
}

// Instalar un manejador de interrupciones en la IDT
void install_interrupt_handler(uint8_t interrupt_number, interrupt_handler_t handler) {
    uint32_t handler_address = (uint32_t)handler;

    idt[interrupt_number].offset_low = handler_address & 0xFFFF;
    idt[interrupt_number].selector = 0x08; // Selector de segmento de código
    idt[interrupt_number].zero = 0x00;
    idt[interrupt_number].type_attr = 0x8E; // Tipo y atributos de la entrada de la IDT
    idt[interrupt_number].offset_high = (handler_address >> 16) & 0xFFFF;
}


void init_idt()
{
    struct IDTDescriptor idt_descriptor;
    idt_descriptor.size = sizeof(idt) - 1;
    idt_descriptor.address = (uint32_t)&idt;

     load_idt(&idt_descriptor);
}