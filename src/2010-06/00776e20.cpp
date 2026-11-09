// from server: 100% by atomic.potato
struct S
{
    int f(int, int);
};

int S::f(int a, int b)
{
    S *p = this;
    p->f(a, b);
    *(int *)p = 0xa52b70;
    *(int *)((char *)p + 0xd8) = 0;
    return (int)p;
}
