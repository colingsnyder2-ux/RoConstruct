// from server: 57% by atomic.potato
struct S_func_004e9330
{
    char pad0[4];
    int m_x;
    void f(int a1);
};

void S_func_004e9330::f(int a1)
{
    m_x = a1;
}

extern "C" void __cdecl func_004e9330(S_func_004e9330 *, int);

struct SpatialFilter
{
    char pad0[8];
    S_func_004e9330 *m_x;
    void f(int);
};

void SpatialFilter::f(int a1)
{
    func_004e9330((S_func_004e9330 *)a1, a1);
    (*(void (__thiscall **)(void *, int))(*(int **)m_x + 12))(m_x, a1);
}
