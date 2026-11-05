// from server: 29% by atomic.potato
struct S
{
    void *f(void *);
    void *g(void *);
};

struct T
{
    void f(void *);
};

void *S::f(void *p)
{
    return p;
}

void *S::g(void *p)
{
    return p;
}

void T::f(void *p)
{
    S *s = (S *)p;
    void *v = s->f((char *)p + 4);
    void *x = *(void **)v;
    s->g(&x);
}
