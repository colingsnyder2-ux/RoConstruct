// from server: 57% by atomic.potato
struct S {
    struct A {
        struct V {
            int (__thiscall *f)(A *, void *, void *);
        } *v;
    } *p;

    int f(void *, void *);
};

int S::f(void *a, void *b)
{
    void *x = a ? (char *)a + 0x1c : 0;
    A::V *v = p->v;
    return v->f((A *)v, x, b);
}
