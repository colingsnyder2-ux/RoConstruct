// from server: 60% by atomic.potato
struct S
{
    int pad0[7];
    void* descriptor;
    int f(void*, void*);
};

extern "C" void* __cdecl sub_5e8c10(void*, void*);

int S::f(void* a, void* b)
{
    char buffer[48];
    void** p = (void**)descriptor;
    void* v = sub_5e8c10(b, buffer);
    typedef void (__thiscall *Fn)(void*, void*, void*);
    Fn fn = *(Fn*)(((char*)*p) + 0x10);
    fn(p, a, v);
    return 0;
}
