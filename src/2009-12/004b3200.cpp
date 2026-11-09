// from server: 87% by atomic.potato
struct S
{
    int f(float a, int b, float c, int d);
};

int S::f(float a, int b, float c, int d)
{
    typedef int (__thiscall *Fn)(void *, int, int, float, float, int);
    Fn fn = *(Fn *)(*(int **)this + 1);
    return fn(this, 0xffff, d, c, a, b);
}
