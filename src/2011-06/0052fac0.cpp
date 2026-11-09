// from server: 78% by atomic.potato
struct S_func_0052fac0
{
    char pad0[80];
    void f();
};

struct T_func_0052eda0
{
    int value0;
    char pad4[12];
    int value10;
    char value14[12];
    unsigned char value20;
    char pad21[15];
    int value30;
    int value34;
    char pad38[4];
    int value3c;
    int value40;
};

extern "C" T_func_0052eda0* __cdecl func_0052eda0(S_func_0052fac0*, int, const char*);

void S_func_0052fac0::f()
{
    T_func_0052eda0* p = func_0052eda0((S_func_0052fac0*)((char*)this + 0x50), 0xC27, (const char*)0xA7F220);
    p->value0 = 0xFFFFFF;
    p->value20 = 0;
    p->value30 = 0;
    p->value34 = 0;
    p->value10 = 0;
    p->value40 = 0;
    p->value3c = 0;
}
