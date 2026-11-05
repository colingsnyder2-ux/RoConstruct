// from server: 42% by colin
struct RBXBaseClass {
    void construct();
};

struct FactoryProduct : RBXBaseClass {
    char pad[0x100];
    void* field_f8;
    void* field_17c;
    void* field_0c;

    FactoryProduct(int arg);
};

extern "C" void __stdcall sub_5830C0(int);
extern "C" void* __stdcall sub_582400();

FactoryProduct::FactoryProduct(int arg) {
    if (arg != 0) {
        *(void**)((char*)this + 0xf8) = (void*)0x7ac5c0;
        *(void**)((char*)this + 0x17c) = (void*)0x7a4ccc;
    }
    sub_5830C0(0);
    void* v = *(void**)((char*)this + 0xf8);
    *(void**)this = (void*)0x7ac57c;
    *(void**)((char*)this + 4) = (void*)0x7ac574;
    *(void**)((char*)this + 0x10) = (void*)0x7ac56c;
    *(void**)((char*)this + 0x14) = (void*)0x7ac55c;
    *(void**)((char*)this + 0x2c) = (void*)0x7ac54c;
    *(void**)((char*)this + 0x44) = (void*)0x7ac53c;
    *(void**)((char*)this + 0x5c) = (void*)0x7ac52c;
    *(void**)((char*)this + 0x74) = (void*)0x7ac51c;
    *(void**)((char*)this + 0x8c) = (void*)0x7ac50c;
    *(void**)((char*)this + 0xe8) = (void*)0x7ac4f4;
    void* ecx = *(void**)((char*)v + 4);
    *(void**)((char*)ecx + (int)this + 0xf8) = (void*)0x7ac4ec;
    void* edx = *(void**)((char*)this + 0xf8);
    void* eax = *(void**)((char*)edx + 4);
    void* ecx2 = (void*)((char*)eax - 0x84);
    *(void**)((char*)eax + (int)this + 0xf4) = ecx2;
    void* result = sub_582400();
    *(void**)((char*)this + 0xc) = result;
}
