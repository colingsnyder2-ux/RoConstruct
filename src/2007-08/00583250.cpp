// from server: 100% by colin
struct FactoryProduct {
    char pad[0xf8];
    void* field_f8;
    char pad2[0x80];
    void* field_17c;
    void construct(int);
    FactoryProduct* init(int);
};

extern "C" void __stdcall sub_583160(int);

FactoryProduct* FactoryProduct::init(int arg) {
    if (arg != 0) {
        *(void**)((char*)this + 0xf8) = (void*)0x7ac5c0;
        *(void**)((char*)this + 0x17c) = (void*)0x7a4ccc;
    }
    sub_583160(0);
    void* p = *(void**)((char*)this + 0xf8);
    *(void**)((char*)this) = (void*)0x7ac664;
    *(void**)((char*)this + 4) = (void*)0x7ac658;
    *(void**)((char*)this + 0x10) = (void*)0x7ac650;
    *(void**)((char*)this + 0x14) = (void*)0x7ac640;
    *(void**)((char*)this + 0x2c) = (void*)0x7ac630;
    *(void**)((char*)this + 0x44) = (void*)0x7ac620;
    *(void**)((char*)this + 0x5c) = (void*)0x7ac610;
    *(void**)((char*)this + 0x74) = (void*)0x7ac600;
    *(void**)((char*)this + 0x8c) = (void*)0x7ac5f0;
    *(void**)((char*)this + 0xe8) = (void*)0x7ac5d8;
    void* ecx = *(void**)((char*)p + 4);
    *(void**)((char*)ecx + (int)this + 0xf8) = (void*)0x7ac5d0;
    void* edx = *(void**)((char*)this + 0xf8);
    void* eax = *(void**)((char*)edx + 4);
    void* v = (void*)((char*)eax - 0x84);
    *(void**)((char*)eax + (int)this + 0xf4) = v;
    return this;
}
