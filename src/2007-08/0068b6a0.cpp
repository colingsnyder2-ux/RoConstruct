// from server: 100% by auto
struct I_func_0068b6a0 {
    char pad[216];
    int m_x;
};
struct S_func_0068b6a0 {
    char pad[132];
    I_func_0068b6a0* m_p;
    int f();
};
int S_func_0068b6a0::f()
{
    return m_p->m_x;
}
