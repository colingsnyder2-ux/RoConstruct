// from server: 59% by atomic.potato
struct S
{
    struct V
    {
        int (__thiscall *f)(V *, void *, void *);
    };

    V *p;
    void *f(void *);
};

void *S::f(void *a)
{
    void *b;
    V *v = *(V **)((char *)this + 0x1c);
    b = a;
    v->f(v, a, b);
    return b;
}
