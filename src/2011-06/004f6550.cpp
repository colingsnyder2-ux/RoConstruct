// from server: 100% by atomic.potato
struct S
{
    int f(int a, int b);
};

int S::f(int a, int b)
{
    struct V
    {
        int **vtable;
    };

    V *p = *(V **)((char *)this + 0x1c);
    typedef int (__thiscall *Fn)(V *, int, int);
    Fn fn = (Fn)p->vtable[2];
    fn(p, a, b);
    return a;
}
