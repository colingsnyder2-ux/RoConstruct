// from server: 68% by colin
struct RBXName {
    void* vtable;
    void* field4;
    void* field8;
    void* fieldC;
};

struct Base {
    void* vtable;
    void* field4;
    void* field8;
    void* fieldC;
    char pad[0xE0];
    RBXName* name;
};

struct FactoryProduct {
    void* vtable;
    void* field4;
    void* field8;
    void* fieldC;
    char pad[0x280];
    void* field294;
    RBXName* name298;

    void construct(int arg);
};

extern "C" void __cdecl sub_5faae0(FactoryProduct* self, int arg);

void FactoryProduct::construct(int arg) {
    RBXName* n = name298;
    field294 = (void*)0x7a4cac;
    void* edx = n->field4;
    *(void**)((char*)edx + (int)this + 0x298) = (void*)0x7a4ca4;

    sub_5faae0(this, arg);

    void* eax = *(void**)((char*)this + 0xec);
    *(void**)this = (void*)0x7c21e4;
    *(void**)((char*)this + 4) = (void*)0x7c21dc;
    *(void**)((char*)this + 0x10) = (void*)0x7c21d4;
    *(void**)((char*)this + 0x14) = (void*)0x7c21c4;
    *(void**)((char*)this + 0x2c) = (void*)0x7c21b4;
    *(void**)((char*)this + 0x44) = (void*)0x7c21a4;
    *(void**)((char*)this + 0x5c) = (void*)0x7c2194;
    *(void**)((char*)this + 0x74) = (void*)0x7c2184;
    *(void**)((char*)this + 0x8c) = (void*)0x7c2174;
    *(void**)((char*)this + 0xe8) = (void*)0x7c2168;
    *(void**)((char*)this + 0x158) = (void*)0x7c2158;
    *(void**)((char*)this + 0x170) = (void*)0x7c214c;
    *(void**)((char*)this + 0x17c) = (void*)0x7c2134;

    void* ecx = *(void**)((char*)eax + 4);
    *(void**)((char*)ecx + (int)this + 0xec) = (void*)0x7c2128;

    void* edx2 = *(void**)((char*)this + 0xec);
    void* eax2 = *(void**)((char*)edx2 + 8);
    *(void**)((char*)eax2 + (int)this + 0xec) = (void*)0x7c2120;

    void* ecx2 = *(void**)((char*)this + 0xec);
    void* edx3 = *(void**)((char*)ecx2 + 0xc);
    *(void**)((char*)edx3 + (int)this + 0xec) = (void*)0x7c2104;

    void* eax3 = *(void**)((char*)this + 0xec);
    void* eax4 = *(void**)((char*)eax3 + 4);
    void* ecx3 = (char*)eax4 - 0x198;
    *(void**)((char*)eax4 + (int)this + 0xe8) = ecx3;

    void* edx4 = *(void**)((char*)this + 0xec);
    void* eax5 = *(void**)((char*)edx4 + 8);
    void* ecx4 = (char*)eax5 - 0x1a0;
    *(void**)((char*)eax5 + (int)this + 0xe8) = ecx4;

    void* edx5 = *(void**)((char*)this + 0xec);
    void* eax6 = *(void**)((char*)edx5 + 0xc);
    void* ecx5 = (char*)eax6 - 0x1a8;
    *(void**)((char*)eax6 + (int)this + 0xe8) = ecx5;
}
