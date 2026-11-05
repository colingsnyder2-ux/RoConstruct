// from server: 52% by atomic.potato
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
    int (*m_call)(int*, int*);
    int f(int*, int*);
};

int SurfaceGetSet::f(int* a, int* b)
{
    int* p;
    if (a)
        p = (int*)((char*)a - 0x1c);
    else
        p = 0;
    p = ((S_func_00750a60*)p)->f();
    return m_call((int*)((char*)p + 0x28), *(int**)b);
}
