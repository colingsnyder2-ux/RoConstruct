// from server: 63% by atomic.potato
extern "C" void __cdecl func_007e5d40(void*);

struct S {
    int field0;
    char field4;
    char field5;
    char pad6[2];
    float field8;
    char padC[4];
    double field10;
    S();
};

S::S()
{
    field0 = 0;
    field4 = 0;
    field5 = 0;
    field8 = 0.0f;
    void* p;
    func_007e5d40(&p);
    field10 = *(double*)p + *(double*)0x9c25e0;
}
