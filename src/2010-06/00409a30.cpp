// from server: 44% by atomic.potato
struct S
{
    unsigned long v0;
    unsigned char pad[8];
    unsigned long vC;
    void *v10;

    void (__thiscall *f())();
};

void (__thiscall *S::f())()
{
    void **p;

    v0 = 0x00a00af8;
    vC = 0x00a00af0;
    vC = 0x00a00968;

    if (v10 != 0)
    {
        p = *(void ***)v10;
        ((void (__thiscall *)(void *))p[4])(v10);
    }

    return 0;
}
