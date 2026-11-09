// from server: 46% by atomic.potato
struct S
{
    void __thiscall f(int, int, int, int);
};

void __thiscall S::f(int a, int b, int c, int d)
{
    struct T
    {
        int a;
        int b;
        int c;
        int d;
    } t;

    t.a = a;
    t.b = b;
    t.c = c;
    t.d = d;
    ((void (__thiscall *)(S *, T *))0x6ac030)(this, &t);
}
