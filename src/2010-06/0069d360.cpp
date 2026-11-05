// from server: 73% by atomic.potato
struct S_func_00636ea0
{
    char pad0[388];
    int m_x;
    int* f();
};

int* S_func_00636ea0::f()
{
    return &m_x;
}

typedef void (__thiscall *Callback)(int*);

extern "C" int* __cdecl func_0069d360(int*);

struct SurfaceGetSet
{
    int m_pad0;
    int m_pad1;
    Callback m_callback;
    void f(int*, int*);
};

void SurfaceGetSet::f(int* a, int* b)
{
    int* p = a ? a - 7 : 0;
    int* x = func_0069d360(p);
    Callback callback = m_callback;
    callback(*(int**)b);
}
