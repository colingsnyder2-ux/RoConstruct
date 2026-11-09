// from server: 43% by colin
struct NonFactoryProduct {
    void* vtable;
    void* field_4;
    void* field_8;
    void* field_c;
    void* field_10;
    void destroy();
};

extern "C" void __cdecl free(void*);

void NonFactoryProduct::destroy()
{
    this->vtable = (void*)0x7a71c0;
    if (this->field_8) {
        free(this->field_8);
    }
    this->field_8 = 0;
    this->field_c = 0;
    this->field_10 = 0;
}
