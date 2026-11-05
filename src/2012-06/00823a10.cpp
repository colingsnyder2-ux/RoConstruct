// from server: 53% by atomic.potato
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
    int m_surface;
    int f(int*, float*);
};

int SurfaceGetSet::f(int* a, float* b)
{
    S_func_00750a60* p = (S_func_00750a60*)a;
    int* q = p ? p->f() : 0;
    int* r = (int*)((char*)q + 40);
    float value = *b;
    return ((int (__thiscall*)(int*, float))m_surface)(r, value);
}
