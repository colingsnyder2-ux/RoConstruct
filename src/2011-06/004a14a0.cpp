// from server: 89% by atomic.potato
struct S_func_004a14a0
{
    unsigned char pad24[0x24];
    unsigned char flag24;
    unsigned char pad25[0x98 - 0x25];
    void *stream;
    int f();
};

int S_func_004a14a0::f()
{
    flag24 = 0;
    if (stream == 0)
        return (int)0x8004020a;

    typedef int (__thiscall *Fn)(void *);
    Fn fn = *(Fn *)((unsigned char *)*(void **)stream + 0x18);
    return fn(stream);
}
