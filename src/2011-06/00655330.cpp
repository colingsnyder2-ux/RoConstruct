// from server: 45% by atomic.potato
struct S
{
    int f();
    int v0;
    char pad[80];
    int v54;
    int v58;
};

int S::f()
{
    v0 = 0xa9a864;
    v54 = 0xa9a85c;
    v54 = 0xa5bfdc;

    if (v58 != 0)
    {
        typedef void (__thiscall *Fn)(void *);
        Fn fn = *(Fn *)(*(int *)v58 + 0x10);
        fn((void *)v58);
    }

    return 0;
}
