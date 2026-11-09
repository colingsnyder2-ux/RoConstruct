// from server: 57% by atomic.potato
struct S_func_0049b030
{
    bool f();
};

struct AbortVerb
{
    char pad0[12];
    void *value;
    void f();
};

void AbortVerb::f()
{
    S_func_0049b030 *p = *(S_func_0049b030 **)((char *)value + 160);
    if (p->f())
        p->f();
}
