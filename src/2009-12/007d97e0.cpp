// from server: 40% by atomic.potato
struct S_func_007b2f20 {
    char pad0[4];
    int m_x;
    void f(int a1);
};

void S_func_007b2f20::f(int a1)
{
    m_x = (int)a1;
}

struct S {
    int f(int a1);
};

int S::f(int a1)
{
    S_func_007b2f20 *p = (S_func_007b2f20 *)a1;
    p->f((int)this);
    return ((int (__thiscall *)(S *, int))(*(int **)this)[2])(this, ((int (__thiscall *)(S_func_007b2f20 *))(*(int **)p)[1])(p));
}
