// from server: 30% by atomic.potato
struct S
{
    void f(int, int, int, int, int, int, int, int);
};

void S::f(int, int, int, int, int, int, int, int)
{
    struct T
    {
        unsigned char a[0x64c68b01];
    };

    T *p = (T *)0;
    p->a[0] &= 0;
}
