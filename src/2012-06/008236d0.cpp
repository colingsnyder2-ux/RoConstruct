// from server: 34% by atomic.potato
struct S_func_00750a60
{
    char pad0[436];
    int m_x;
    int* f();
};

int* S_func_00750a60::f()
{
    return &m_x;
}

struct SurfaceGetSet
{
    int (*m_func)(int);
    int f(int*, int*);
};

int SurfaceGetSet::f(int* a, int* b)
{
    S_func_00750a60* p;
    if (a)
        p = (S_func_00750a60*)((char*)a - 28);
    else
        p = 0;

    int* x = p->f();
    int (*func)(int) = m_func;
    return func(*b);
}
