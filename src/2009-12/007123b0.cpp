// from server: 70% by atomic.potato
struct S_func_007010d0
{
};

extern "C" S_func_007010d0* __cdecl f_007010d0(void*);

struct S_func_008c62c0
{
    char pad0[32];
    int m_x;
    int f();
};

int S_func_008c62c0::f()
{
    return m_x;
}

extern "C" int f_008c62c0(S_func_008c62c0*);

int* f_007123b0(void* p)
{
    S_func_007010d0* a = f_007010d0(p);
    if (a)
    {
        S_func_008c62c0* b = (S_func_008c62c0*)((char*)a + 8);
        if (f_008c62c0(b))
            return (int*)((char*)b - 8);
    }
    return 0;
}
