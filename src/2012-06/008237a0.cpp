// from server: 46% by atomic.potato
struct S_func_00750a60 {
    char pad0[436];
    int m_x;
    int* f();
};

int* S_func_00750a60::f()
{
    return &m_x;
}

struct SurfaceGetSet {
    int m_pad0;
    int m_pad1;
    int (*m_function)(int*, int);

    int f(int* a, int* b);
};

int SurfaceGetSet::f(int* a, int* b)
{
    SurfaceGetSet* p = this;
    S_func_00750a60* q = 0;

    if (a)
        q = (S_func_00750a60*)((char*)a - 0x1c);

    int* r = q ? q->f() : 0;
    return m_function(r + 2, *b);
}
