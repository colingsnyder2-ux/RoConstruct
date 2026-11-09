// from server: 68% by atomic.potato
extern "C" void __cdecl G1_func_00568a30(void *);
extern "C" void __cdecl G2_func_00982114(void *);

struct S
{
    int f();
    unsigned char pad[4];
    void *p;
};

int S::f()
{
    if (p != 0)
    {
        if (pad[5] != 0)
            G1_func_00568a30((char *)p + 0x18);
        G2_func_00982114(p);
    }
    return 0;
}
