// from server: 29% by atomic.potato
struct S
{
    int f(void *);
    void *g(void *);
    void h(void *);
};

void *S::g(void *p)
{
    return p;
}

void S::h(void *p)
{
    (void)p;
}

int S::f(void *p)
{
    void *value = g((char *)p + 4);
    void *arg = *(void **)value;
    h(&arg);
    return 0;
}
