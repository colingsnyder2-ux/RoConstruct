// from server: 53% by atomic.potato
struct X_004b2910 {
    char pad_0[0x2c];
    char f_2c[0xc];
    char f_38[0x10];
    char pad_48[0x58];
    void* f_a0;
    void init();
};

extern "C" void __stdcall sub_005e3da0(void*, void*);
extern "C" void* __stdcall sub_0062d880();
extern "C" void __stdcall sub_004541e0(void*, int, void*);

void X_004b2910::init() {
    sub_005e3da0((void*)0xc1a270, (void*)0xa774b8);
    *(void**)this = (void*)0xa76f84;
    void* p1 = sub_0062d880();
    *(void**)((char*)this + 0x30) = p1;
    *(char*)((char*)p1 + 0x15) = 1;
    void* q1 = *(void**)((char*)this + 0x30);
    *(void**)((char*)q1 + 4) = q1;
    void* r1 = *(void**)((char*)this + 0x30);
    *(void**)r1 = r1;
    void* s1 = *(void**)((char*)this + 0x30);
    *(void**)((char*)s1 + 8) = s1;
    *(void**)((char*)this + 0x34) = 0;
    void* p2 = sub_0062d880();
    *(void**)((char*)this + 0x3c) = p2;
    *(char*)((char*)p2 + 0x15) = 1;
    void* q2 = *(void**)((char*)this + 0x3c);
    *(void**)((char*)q2 + 4) = q2;
    void* r2 = *(void**)((char*)this + 0x3c);
    *(void**)r2 = r2;
    void* s2 = *(void**)((char*)this + 0x3c);
    *(void**)((char*)s2 + 8) = s2;
    *(void**)((char*)this + 0x40) = 0;
    *(void**)((char*)this + 0x48) = 0;
    *(void**)((char*)this + 0x4c) = 0;
    *(void**)((char*)this + 0x50) = 0;
    *(void**)((char*)this + 0x58) = 0;
    *(void**)((char*)this + 0x5c) = 0;
    *(void**)((char*)this + 0x60) = 0;
    *(void**)((char*)this + 0x68) = 0;
    *(void**)((char*)this + 0x6c) = 0;
    *(void**)((char*)this + 0x70) = 0;
    *(void**)((char*)this + 0x78) = 0;
    *(void**)((char*)this + 0x7c) = 0;
    *(void**)((char*)this + 0x80) = 0;
    *(void**)((char*)this + 0x88) = 0;
    *(void**)((char*)this + 0x8c) = 0;
    *(void**)((char*)this + 0x90) = 0;
    *(void**)((char*)this + 0x98) = 0;
    *(void**)((char*)this + 0x9c) = 0;
    *(void**)((char*)this + 0xa0) = 0;
    sub_004541e0(this, 0, (void*)0xa774b0);
    sub_004541e0(this, 1, (void*)0xa774a4);
}

X_004b2910* func_004b2910(X_004b2910* x) { x->init(); return x; }
