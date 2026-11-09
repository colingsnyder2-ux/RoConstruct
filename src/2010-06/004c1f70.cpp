// from server: 87% by atomic.potato
struct S
{
    char f();
};

struct V
{
    char (*a)(void *);
};

extern V *g;

char S::f()
{
    void *p = *(void **)((char *)this + 0x15c);
    if (p)
    {
        V *v = g;
        return v->a((char *)p + 0x1c);
    }
    return 0;
}
