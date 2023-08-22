// Definición de la Entrada de la Tabla de Descriptores de Interrupciones (IDT)
struct IDTEntry {
    uint16_t offset_low;
    uint16_t selector;
    uint8_t zero;
    uint8_t type_attr;
    uint16_t offset_high;
} __attribute__((packed));

// Definición de la estructura de la IDT
struct IDTDescriptor {
    uint16_t size;
    uint32_t address;
} __attribute__((packed));



// Definiciones de estructuras y funciones del controlador de interrupciones
// (Esto puede variar según la plataforma y el sistema operativo)
typedef void (*interrupt_handler_t)();
void configure_idt_entry(uint8_t interrupt_number, interrupt_handler_t handler);
void load_idt(struct IDTDescriptor* idt_descriptor);


// Definir un arreglo de entradas de la IDT
struct IDTEntry idt[256];