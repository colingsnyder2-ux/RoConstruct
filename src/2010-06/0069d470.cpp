// from server: 48% by atomic.potato
struct S_func_00636ea0 {
    char pad0[388];
    int m_x;
    int *f();
};

int *S_func_00636ea0::f()
{
    return &m_x;
}

struct SurfaceGetSet {
    char pad0[8];
    int (*m_call)(int *, float);
    void f(int *, float *);
};

void SurfaceGetSet::f(int *a, float *b)
{
    S_func_00636ea0 *p = (S_func_00636ea0 *)a;
    int *q = p ? p->f() : 0;
    ((int (*)(int *, float))m_call)(q + 6, *b);
}
