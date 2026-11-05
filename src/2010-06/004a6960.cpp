// from server: 59% by atomic.potato
struct S
{
    void f();
};

struct G
{
    int (**vtable)();
};

extern G *g_00c044bc;

void S::f()
{
    int *p = (int *)this;
    int *q = p ? p + 7 : 0;
    G *g = g_00c044bc;
    ((void (__thiscall *)(G *, int *))g->vtable[4])(g, q);
}
