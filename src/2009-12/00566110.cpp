// from server: 50% by atomic.potato
struct S
{
    void f(int, int, int, int, int);
};

void S::f(int a, int b, int c, int d, int e)
{
    typedef void (__thiscall *Fn)(S *, int, int, int, int, int, int);
    Fn fn = (Fn)(*(unsigned int **)this)[0x148 / 4];
    fn(this, d, e, e, e, 0x1b, e);
}
