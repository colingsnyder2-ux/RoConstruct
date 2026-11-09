// from server: 53% by atomic.potato
struct S
{
    typedef int (__thiscall *Callback)(int, int, int);
    int a0;
    int a1;
    int a2;
    int a3;
    int a4;
    int f(int);
};

int S::f(int value)
{
    Callback callback = (Callback)a0;
    return (int)callback(a1 + a2, value, a3);
}
