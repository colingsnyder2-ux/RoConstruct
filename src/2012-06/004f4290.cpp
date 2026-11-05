// from server: 100% by tester
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

    V *p = *(V **)((char *)this + 0x44);
    typedef int (__thiscall *Fn)(V *, int, int);
    Fn fn = (Fn)p->vtable[2];
    fn(p, a, b);
    return a;
}