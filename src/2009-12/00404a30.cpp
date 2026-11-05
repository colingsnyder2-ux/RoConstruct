// from server: 80% by atomic.potato
struct S {
    int f(int, int);
};

struct V {
    void (__thiscall *a)();
    void (__thiscall *b)();
    void (__thiscall *c)();
};

extern V *g;

int S::f(int, int x)
{
    V *v = g;
    if (x)
        v->b();
    else
        v->c();
    return 0;
}
