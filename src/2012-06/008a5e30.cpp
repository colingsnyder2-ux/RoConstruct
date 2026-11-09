// from server: 50% by atomic.potato
typedef int (__thiscall *Fn1)(void *);
typedef void *(__cdecl *Fn2)(int);
typedef int (__stdcall *Fn3)(void *);

struct S
{
    void *field0;

    int f();
};

int S::f()
{
    void *p = *(void **)((char *)field0 + 0xac4);
    int v = ((Fn1)0x495f40)(p);
    if (!v)
        return 0;
    v = (int)((Fn2)0x983b6a)(v);
    return ((Fn3)*(void **)0xb229ec)((void *)v);
}
