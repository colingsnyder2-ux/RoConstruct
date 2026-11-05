// from server: 86% by atomic.potato
struct S
{
    int f();
};

int S::f()
{
    struct V
    {
        int x;
        int (__thiscall *g)(V *);
    };

    V *p = *(V **)((char *)this + 12);
    V *q = (V *)((char *)p + 280);
    int r = q->g(q);
    return *(int *)((char *)r + 316) == 3;
}
