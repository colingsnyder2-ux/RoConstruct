// from server: 100% by auto
struct I_func_0064b0a0 {
    char pad[176];
    int m_x;
};
struct S_func_0064b0a0 {
    char pad[36];
    I_func_0064b0a0* m_p;
    int f();
};
int S_func_0064b0a0::f()
{
    return m_p->m_x;
}
