// from server: 32% by atomic.potato
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
    int* (__thiscall *m_f)(int*, int);
    int* f(int* a, int* b);
};

int* SurfaceGetSet::f(int* a, int* b)
{
    S_func_0066c140* p = a ? (S_func_0066c140*)((char*)a - 0x1c) : 0;
    int* q = p ? p->f() : 0;
    int* r = (int*)((char*)q + 8);
    return m_f(r, *b);
}
