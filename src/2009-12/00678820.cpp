// from server: 52% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    struct V
    {
        int pad[72];
        int (*g)(V *);
        int state;
    };

    V *p = *(V **)((char *)this + 12);
    p->g(p);
    return p->state == 1;
}
