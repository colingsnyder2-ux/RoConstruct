// from server: 100% by Intel
extern "C" void __cdecl external_func(void* param);

struct TypedPropertyDescriptor {
    char pad[0x28];
    void* field_28;
    
    TypedPropertyDescriptor* method(int arg);
};

TypedPropertyDescriptor* TypedPropertyDescriptor::method(int arg) {
    external_func(field_28);
    
    *(void**)this = (void*)0xB43C2C;
    
    if (arg & 1) {
        external_func(this);
    }
    
    return this;
}
