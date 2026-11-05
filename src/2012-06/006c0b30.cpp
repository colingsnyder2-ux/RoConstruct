// from server: 53% by atomic.potato
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
    V *p = *(V **)((char *)this + 0x28);
    typedef int (__thiscall *Fn)(V *, int, int);
    return ((Fn)p->vtable[0])(p, a, b);
}

extern "C" int __stdcall sub_7450e0(int, int);

int __stdcall sub_6c0b30(int a, int b)
{
    int v = 0;
    int r = ((S *)a)->f(b, (int)&v);
    sub_7450e0(a, r);
    return a;
}
