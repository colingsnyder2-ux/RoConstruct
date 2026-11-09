// from server: 20% by atomic.potato
struct Vlength_error {
    void* vtable;
    char unknown[0x24]; // Padding between vtable and offset 0x28
    void* field_28;
    void* field_3C;

    Vlength_error();
};

void* const vtable_a88824 = reinterpret_cast<void*>(0xa88824);
void* const field_a8881c = reinterpret_cast<void*>(0xa8881c);
void* const field_a8880c = reinterpret_cast<void*>(0xa8880c);
void* const field_a5bee8 = reinterpret_cast<void*>(0xa5bee8);

void base_ctor_589320(Vlength_error*);

Vlength_error::Vlength_error() {
    vtable = vtable_a88824;
    field_28 = field_a8881c;
    field_3C = field_a8880c;
    field_3C = field_a5bee8;
    base_ctor_589320(this);
}
