// from server: 35% by atomic.potato
struct S
{
    int f(void *, void *);
};

int S::f(void *, void *p)
{
    struct V
    {
        int (**vtable)();
    };

    int a = ((V *)p)->vtable[1]();
    return f(this, p);
}
