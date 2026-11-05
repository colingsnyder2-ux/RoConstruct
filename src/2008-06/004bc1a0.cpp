// from server: 100% by atomic.potato
extern "C" void* __cdecl sub_6a0920(unsigned int size);

struct S {
    char pad0[8];
    void* m8;
    void* mC;
    int m10;
    int m14;
    S* f();
};

S* S::f()
{
    m8 = sub_6a0920(0x128);
    *(char*)((char*)m8 + 0x120) = 0;
    mC = m8;
    void* p = sub_6a0920(0x128);
    *(void**)((char*)m8 + 0x124) = p;
    int i = 6;
    do {
        void* q = *(void**)((char*)m8 + 0x124);
        m8 = q;
        void* r = sub_6a0920(0x128);
        *(void**)((char*)m8 + 0x124) = r;
        *(char*)((char*)m8 + 0x120) = 0;
        --i;
    } while (i != 0);
    void* a = *(void**)((char*)m8 + 0x124);
    *(void**)((char*)a + 0x124) = mC;
    m8 = mC;
    *(void**)this = mC;
    *(void**)((char*)this + 4) = mC;
    m14 = 0;
    m10 = 0;
    return this;
}
