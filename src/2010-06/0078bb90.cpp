// from server: 40% by atomic.potato
struct S_func_007637e0
{
    char pad0[4];
    int m_x;
    void f(int a1);
};

void S_func_007637e0::f(int a1)
{
    m_x = a1;
}

struct S
{
    int f(S_func_007637e0* a1);
};

int S::f(S_func_007637e0* a1)
{
    a1->f((int)this);
    return ((int (__thiscall *)(S*, int))(*(int**)this)[2])(this,
        ((int (__thiscall *)(S_func_007637e0*))(*(int**)a1)[1])(a1));
}
