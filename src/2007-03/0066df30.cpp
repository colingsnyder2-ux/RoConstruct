// from server: 100% by auto
struct I_func_0066df30 {
    char pad[176];
    int m_x;
};
struct S_func_0066df30 {
    char pad[132];
    I_func_0066df30* m_p;
    int f();
};
int S_func_0066df30::f()
{
    return m_p->m_x;
}
