// from server: 85% by atomic.potato
struct S
{
    void f(S *);
    void g(void *);
};

void S::f(S *p)
{
    g((char *)p + 0x20);
}
