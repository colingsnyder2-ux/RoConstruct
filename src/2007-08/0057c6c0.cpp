// from server: 56% by colin
extern "C" void __cdecl func_0062fc62(void*);

struct Workspace {
    void* vtable;
    void* field_4;
    void* field_8;
    void* field_c;
    void* field_10;
    void destroy();
};

void Workspace::destroy()
{
    this->vtable = (void*)0x7ab754;
    if (this->field_8) {
        func_0062fc62(this->field_8);
    }
    this->field_8 = 0;
    this->field_c = 0;
    this->field_10 = 0;
}
