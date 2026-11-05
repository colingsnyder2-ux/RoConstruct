// from server: 100% by auto
struct I_func_00686e70 {
    char pad[316];
    int m_x;
};
struct S_func_00686e70 {
    char pad[176];
    I_func_00686e70* m_p;
    int f();
};
int S_func_00686e70::f()
{
    return m_p->m_x;
}
