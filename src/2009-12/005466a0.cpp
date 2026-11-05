// from server: 34% by atomic.potato
struct S
{
    int f();
    int g(int *);
    int value;
};

int S::f()
{
    S *p = (S *)((char *)this + 0xc0);
    int a = p->value;
    return g(&a);
}
