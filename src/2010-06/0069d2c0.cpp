// from server: 52% by atomic.potato
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

extern "C" int* __cdecl func_00636ea0();

struct S
{
    int m_pad0;
    int m_pad1;
    int (__thiscall *m_func)(int);
    int f(void*, int*);
};

int S::f(void* p, int* q)
{
    S_func_00636ea0* x = p ? (S_func_00636ea0*)((char*)p - 0x1c) : 0;
    int* y = func_00636ea0();
    y += 2;
    return m_func(*q);
}
