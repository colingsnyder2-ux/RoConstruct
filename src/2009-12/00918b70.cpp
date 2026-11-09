// from server: 24% by atomic.potato
struct S
{
    void f(void *);
    void g(void *);
};

void S::f(void *p)
{
    *(void **)((char *)p + 0x0c) = this;
    g(p);
}
