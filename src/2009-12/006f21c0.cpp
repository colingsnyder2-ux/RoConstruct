// from server: 49% by atomic.potato
struct S_func_006cb2b0
{
    char pad0[388];
    int m_x;
    int* f();
};

int* S_func_006cb2b0::f()
{
    return &m_x;
}

extern "C" int* __cdecl f_006cb2b0();

struct SurfaceGetSet
{
    int m_pad;
    int (__thiscall *m_function)(int*, int);
    int invoke(int* a, int* b);
};

int SurfaceGetSet::invoke(int* a, int* b)
{
    S_func_006cb2b0* p;
    if (a)
        p = (S_func_006cb2b0*)((char*)a - 28);
    else
        p = 0;

    int* x = f_006cb2b0();
    return m_function(x + 2, *b);
}
