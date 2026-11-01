// from server: 100% by auto
struct I_func_007dc3a0 {
    char pad[256];
    int m_x;
};
struct S_func_007dc3a0 {
    char pad[36];
    I_func_007dc3a0* m_p;
    int f();
};
int S_func_007dc3a0::f()
{
    return m_p->m_x;
}
