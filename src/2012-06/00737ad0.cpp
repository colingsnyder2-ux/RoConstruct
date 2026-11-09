// from server: 50% by atomic.potato
struct S
{
    void *f(void *);
    void *g(void *);
};

void *S::f(void *p)
{
    return 0;
}

void *S::g(void *p)
{
    return 0;
}

struct EnumDesc : S
{
    void *f(void *);
};

void *EnumDesc::f(void *p)
{
    void *v = f((char *)p + 4);
    void *x = *(void **)v;
    return g(&x);
}
