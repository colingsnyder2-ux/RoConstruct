// from server: 58% by atomic.potato
struct S
{
    int f(int, int, int);
    int *p;
};

typedef int (__thiscall *Fn)(int *);

int S::f(int a, int b, int c)
{
    if (a)
    {
        int *q = p;
        Fn fn = *(Fn *)(*(int **)q + 0x14);
        fn((int *)(a + 0x238));
    }
    else
    {
        int *q = p;
        Fn fn = *(Fn *)(*(int **)q + 0x14);
        fn(0);
    }
    return 1;
}
