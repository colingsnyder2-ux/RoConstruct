// from server: 50% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    struct T
    {
        int a;
        int b;
        int c;
    };

    T *p = *(T **)((char *)this + 8);
    p->b += p->a;
    return p->c;
}
