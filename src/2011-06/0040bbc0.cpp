// from server: 59% by atomic.potato
struct S {
    char pad0[0xc];
    void* field_c;
    char pad10[0x1c];
    void* field_2c;
    void* field_28;
    void* field_0;
    void dtor();
};

extern "C" void __stdcall sub_a404d0(void*);
extern "C" void __stdcall sub_a40a64(void*);

void S::dtor() {
    field_0 = (void*)0xa5c238;
    field_28 = (void*)0xa5c230;
    field_28 = (void*)0xa5bfdc;
    if (field_2c) {
        void** v = (void**)field_2c;
        void (*fn)(void*) = (void (*)(void*))v[4];
        fn(field_2c);
    }
    field_0 = (void*)0xa5bf00;
    sub_a404d0(&field_c);
    sub_a40a64(this);
}
