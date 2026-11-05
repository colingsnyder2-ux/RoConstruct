// from server: 34% by atomic.potato
struct S
{
    int f();
    int a;
    int b;
    int c;
    int d;
};

int S::f()
{
    typedef int (__thiscall *Fn)(int, int, int);
    Fn fn = (Fn)d;
    return fn(a, b, c);
}
