// from server: 67% by atomic.potato
struct S
{
    virtual void f(void *);
    virtual void h();
    void g(void *);
};

void S::g(void *p)
{
    h();
    f(p);
}
