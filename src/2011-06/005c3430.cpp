// from server: 55% by atomic.potato
extern "C" void __cdecl sub_80A058(void*);
extern "C" void __cdecl sub_401AE0(void*, void*, void*);
extern "C" void __cdecl sub_420410(void*);
extern "C" void __cdecl sub_5E3930(void*);

struct S {
    char pad0[0x18];
    void** begin18;
    void** end1c;
    char pad20[0xc];
    void* p2c;
    void* p30;
    void* p34;
    void* p38;
    void* p3c;
    void* p40;
    void* p44;
    void* p48;
    void* p4c;
    void* p50;
    char pad54[0x14];
    void* p68;
    void* p6c;
    void* p70;
    char pad74[4];
    void* p78;
    void* p7c;
    void* p80;
    char pad84[4];
    void* p88;
    void* p8c;
    void* p90;
    char pad94[4];
    void* p98;
    void* p9c;
    void* pa0;
    void dtor();
};

void S::dtor() {
    *(void**)this = (void*)0xa8ec00;
    ++*(int*)0xcca7a0;
    void** it = begin18;
    void** last = end1c;
    while (it != last) {
        void* p = *it;
        if (p) {
            void** vt = *(void***)p;
            ((void (__thiscall*)(void*, int))vt[0])(p, 1);
        }
        ++it;
    }
    if (p98) { sub_80A058(p98); }
    p98 = 0; p9c = 0; pa0 = 0;
    if (p88) { sub_80A058(p88); }
    p88 = 0; p8c = 0; p90 = 0;
    if (p78) { sub_80A058(p78); }
    p78 = 0; p7c = 0; p80 = 0;
    if (p68) { sub_80A058(p68); }
    p68 = 0; p6c = 0; p70 = 0;
    sub_420410((char*)this + 0x54);
    if (p48) { sub_80A058(p48); }
    p48 = 0; p4c = 0; p50 = 0;
    {
        void* a = p3c;
        void* b = *(void**)a;
        void* tmp;
        sub_401AE0(&tmp, b, a);
        sub_80A058(p38);
        p38 = 0; p3c = 0;
    }
    {
        void* a = p30;
        void* b = *(void**)a;
        void* tmp;
        sub_401AE0(&tmp, b, a);
        sub_80A058(p2c);
        p2c = 0; p30 = 0;
    }
    sub_5E3930(this);
}
