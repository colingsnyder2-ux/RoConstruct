// from server: 40% by atomic.potato
// roc 2012-06 00761d30  unit: RBX::VExplosion::?$FactoryProduct  size: 384 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00761d30

extern "C" void __cdecl sub_982114(void*);
extern "C" void __cdecl sub_423e20();
extern "C" void __cdecl sub_425320();
extern "C" void __cdecl sub_6cb3c0();

struct S {
    char pad0[0x20];
    int* begin;
    int* end;
    char pad28[0x18];
    char pad40[0x10];
    void* p50;
    void* p54;
    void* p58;
    char pad5c[0x14];
    void* p70;
    void* p74;
    void* p78;
    void* p80;
    void* p84;
    void* p88;
    void* p90;
    void* p94;
    void* p98;
    void* pA0;
    void* pA4;
    void* pA8;
    void dtor();
};

void S::dtor() {
    *(int*)this = 0xbaede0;
    ++*(int*)0xe487b4;
    int* edi = begin;
    int* ebp = end;
    if (edi != ebp) {
        do {
            int* ecx = (int*)*edi;
            if (ecx != 0) {
                int* eax = (int*)*ecx;
                void (__thiscall *fn)(void*, int) = (void (__thiscall *)(void*, int))*(int*)eax;
                fn((void*)ecx, 1);
            }
            edi++;
        } while (edi != ebp);
    }
    if (pA0) { sub_982114(pA0); }
    pA0 = 0; pA4 = 0; pA8 = 0;
    if (p90) { sub_982114(p90); }
    p90 = 0; p94 = 0; p98 = 0;
    if (p80) { sub_982114(p80); }
    p80 = 0; p84 = 0; p88 = 0;
    if (p70) { sub_982114(p70); }
    p70 = 0; p74 = 0; p78 = 0;
    sub_423e20();
    if (p50) { sub_982114(p50); }
    p50 = 0; p54 = 0; p58 = 0;
    sub_425320();
    sub_982114(*(void**)((char*)this + 0x44));
    *(void**)((char*)this + 0x44) = 0;
    *(void**)((char*)this + 0x48) = 0;
    sub_425320();
    sub_982114(*(void**)((char*)this + 0x38));
    *(void**)((char*)this + 0x38) = 0;
    *(void**)((char*)this + 0x3c) = 0;
    sub_6cb3c0();
}
