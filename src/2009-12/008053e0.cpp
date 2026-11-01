// from server: 21% by atomic.potato
struct VTable
{
    void (__thiscall *f74)(void *, void *);
};

struct S
{
    void *get();
    void f(void *);
};

void *S::get()
{
    return 0;
}

void S::f(void *arg)
{
    void *p = get();
    VTable *v = *(VTable **)p;
    v->f74(p, arg);
}
