// from server: 33% by atomic.potato
struct S
{
    unsigned char f(int, int);
    int value;
};

unsigned char S::f(int a, int b)
{
    int *p = &b;
    int *q = &a;
    int *c = 0;
    if (p != q)
    {
        c = (int *)*p;
        *p = 0;
    }
    if (c)
    {
        int **v = (int **)*c;
        void (__thiscall *fn)(int *, int) = (void (__thiscall *)(int *, int))*v;
        fn((int *)*v, 1);
    }
    return (unsigned char)value;
}
