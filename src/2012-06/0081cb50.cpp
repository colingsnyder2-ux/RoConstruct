// from server: 74% by atomic.potato
struct S
{
    int f();
    char pad[0xac];
    struct T
    {
        struct V
        {
            int (__thiscall *g)(T *);
        };
        V *v;
        T *next;
    };
    T *value;
};

int S::f()
{
    T *p = value;
    while (p->v->g(p) != 5)
        p = p->next;
    return p->v->g(p);
}
