// from server: 41% by atomic.potato
// roc 2009-12 00717690  unit: RBX::VRotate::?$FactoryProduct  size: 136 bytes

extern "C" void* __cdecl sub_7F3860(unsigned int);
extern "C" void __cdecl sub_7B4B90(void*);
extern "C" void __cdecl sub_716FD0(void*, void*);

struct S {
    void* field0;
    void* field4;
    char pad8[0x10];
    void* field18;
    void* field1C;
    char pad20[0x74];
    void* field94;
    void* method();
};

void* S::method() {
    void* p = sub_7F3860(0xD0);
    if (p) {
        sub_7B4B90(p);
    } else {
        p = 0;
    }
    sub_716FD0(this, p);
    field0 = (void*)0x9DF2DC;
    field4 = (void*)0x9DF2D0;
    field18 = (void*)0x9DF2C4;
    field1C = (void*)0x9DF2BC;
    field94 = (void*)0x9DF2A4;
    return this;
}
