// from server: 68% by atomic.potato
struct S_func_0066c140
{
    char pad0[388];
    int m_x;
    int *f();
};

int *S_func_0066c140::f()
{
    return &m_x;
}

extern "C" int * __cdecl f_0066c140(int *);

struct SurfaceGetSet
{
    int m_pad0;
    int m_pad1;
    int (*m_call)(int *, float);
    int method(int *, float *);
};

int SurfaceGetSet::method(int *p, float *v)
{
    int *x = p ? p - 7 : 0;
    int *y = f_0066c140(x);
    return m_call(y + 4, *v);
}
