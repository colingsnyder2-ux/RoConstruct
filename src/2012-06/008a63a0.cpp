// from server: 54% by atomic.potato
struct S
{
    char pad[12];
    int *p;
    int f();
};

typedef void *(__thiscall *Fn495f40)(void *);
typedef void *(__cdecl *Fn983b6a)(void *);
typedef void (__thiscall *FnGlobal)(void *, void *);

int S::f()
{
    void *a = ((Fn495f40)0x495f40)((void *)p[0x2b1]);
    if (a)
    {
        void *b = ((Fn983b6a)0x983b6a)(a);
        ((FnGlobal)(*(void ***)0x00b229ec))((void *)0x00dec1f4, b);
    }
    return 0;
}
