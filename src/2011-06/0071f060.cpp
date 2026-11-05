// from server: 30% by atomic.potato
struct S_func_0066c140
{
    char pad0[388];
    int m_x;
    int* f();
};

int* S_func_0066c140::f()
{
    return &m_x;
}

struct SurfaceGetSet
{
    char pad0[8];
    int (*m_function)(int*, int);
    int f(int*, int*);
};

int SurfaceGetSet::f(int* a, int* b)
{
    S_func_0066c140* p = (S_func_0066c140*)0;
    if (a)
        p = (S_func_0066c140*)((char*)a - 0x1c);
    int* q = p->f() + 4;
    return m_function(q, *b);
}
