// from server: 47% by colin
struct S {
    char pad[0x2a0];
    void* field_0xec;
    void* field_0x294;
    void* field_0x298;
    void construct();
};

extern "C" void __stdcall sub_578ed0(void*);

void S::construct() {
    void* p = field_0x298;
    field_0x294 = (void*)0x7a4cac;
    *(void**)((char*)p + 4) = (void*)0x7a4ca4;
    *(void**)((char*)p + 4 + 0x298) = (void*)0x7a4ca4;
    sub_578ed0(this);
    void* e = field_0xec;
    *(void**)this = (void*)0x7b3604;
    *(void**)((char*)this + 4) = (void*)0x7b35fc;
    *(void**)((char*)this + 0x10) = (void*)0x7b35f4;
    *(void**)((char*)this + 0x14) = (void*)0x7b35e4;
    *(void**)((char*)this + 0x2c) = (void*)0x7b35d4;
    *(void**)((char*)this + 0x44) = (void*)0x7b35c4;
    *(void**)((char*)this + 0x5c) = (void*)0x7b35b4;
    *(void**)((char*)this + 0x74) = (void*)0x7b35a4;
    *(void**)((char*)this + 0x8c) = (void*)0x7b3594;
    *(void**)((char*)this + 0xe8) = (void*)0x7b3588;
    *(void**)((char*)this + 0x158) = (void*)0x7b3578;
    *(void**)((char*)this + 0x170) = (void*)0x7b356c;
    *(void**)((char*)this + 0x17c) = (void*)0x7b3554;
    void* q = *(void**)((char*)e + 4);
    *(void**)((char*)q + 0xec) = (void*)0x7b3548;
    void* r = *(void**)((char*)e + 8);
    *(void**)((char*)r + 0xec) = (void*)0x7b3540;
    void* s = *(void**)((char*)e + 0xc);
    *(void**)((char*)s + 0xec) = (void*)0x7b3524;
    void* t = *(void**)((char*)e + 4);
    *(void**)((char*)t + 0xe8) = (void*)((char*)t - 0x198);
    void* u = *(void**)((char*)e + 8);
    *(void**)((char*)u + 0xe8) = (void*)((char*)u - 0x1a0);
    void* v = *(void**)((char*)e + 0xc);
    *(void**)((char*)v + 0xe8) = (void*)((char*)v - 0x1a8);
}
