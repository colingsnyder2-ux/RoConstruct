// from server: 29% by atomic.potato
struct S
{
    void *f(void *);
    void *g(void *);
};

void *S::f(void *p)
{
    return p;
}

void *S::g(void *p)
{
    return p;
}

struct T : S
{
    void h(void *);
};

void T::h(void *p)
{
    void *q = f((char *)p + 4);
    void *v = *(void **)q;
    g(&v);
}
