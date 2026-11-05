// from server: 75% by atomic.potato
struct S
{
    int f(int, int, int, int);
    void **v;
};

int S::f(int a, int b, int c, int d)
{
    void **p = v;
    typedef int (__thiscall *Fn)(void *, int, int, int *, int);
    int x = 0;
    Fn fn = (Fn)((void **)p[0])[1];
    fn(p, a, b, &x, 0);
    return a;
}
