// from server: 42% by atomic.potato
struct S {
    char pad0[8];
    void* p8;
    void* pC;
    char pad10[4];
    void* p14;
    void* p18;
    void* p1C;
    void* p20;
    void* p24;
    void* p28;
    void* p2C;
    char pad30[0x34];
    void* p64;
    S();
};

extern "C" void __stdcall sub_7a8924(void*);

S::S()
{
    p1C = 0;
    p8 = (void*)0xa12c70;
    pC = 0;
    p14 = 0;
    p18 = (void*)0xa12bd4;
    p20 = 0;
    p24 = 0;
    p28 = 0;
    p2C = 0;
    sub_7a8924(&pad30[0]);
    *(void**)(&pad30[0]) = (void*)0xa12bdc;
    p64 = 0;
}
