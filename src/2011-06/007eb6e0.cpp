// from server: 100% by atomic.potato
struct S
{
    int f(int, int);
    void g(int, int);
};

int S::f(int a, int b)
{
    g(a, b);
    *(int *)this = 0xabece8;
    *((int *)this + 1) = 0xabecdc;
    return (int)this;
}
