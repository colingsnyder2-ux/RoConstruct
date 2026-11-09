// from server: 47% by atomic.potato
extern "C" void __cdecl G1_func_007a01e0(void *);
extern "C" void __cdecl G2_func_00982114(void *);

struct S
{
    int f();
    void *field4;
    char field8;
};

int S::f()
{
    void *p = field4;
    if (p != 0)
    {
        if (field8 != 0)
            G1_func_007a01e0((char *)p + 4);
        G2_func_00982114(p);
    }
    return 0;
}
