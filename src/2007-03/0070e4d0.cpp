// from server: 100% by auto
struct I_func_0070e4d0 {
    char pad[52];
    int m_x;
};
struct S_func_0070e4d0 {
    char pad[48];
    I_func_0070e4d0* m_p;
    int f();
};
int S_func_0070e4d0::f()
{
    return m_p->m_x;
}
