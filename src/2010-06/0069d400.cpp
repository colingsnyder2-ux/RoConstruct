// from server: 43% by atomic.potato
struct S_func_00636ea0 {
    char pad0[388];
    int m_x;
    int* f();
};

int* S_func_00636ea0::f()
{
    return &m_x;
}

struct S {
    int m_vtable;
    int m_data;
    int f(int*, int*);
};

int* f_00636ea0(int*);

int S::f(int* a, int* b)
{
    int* p = a ? f_00636ea0(a - 7) : 0;
    p = p + 6;
    int value = *b;
    return ((int (__thiscall *)(int*, int))(*(int**)((char*)this + 8)))(p, value);
}
