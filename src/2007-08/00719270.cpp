// from server: 100% by auto
struct I_func_00719270 {
    char pad[52];
    int m_x;
};
struct S_func_00719270 {
    char pad[48];
    I_func_00719270* m_p;
    int f();
};
int S_func_00719270::f()
{
    return m_p->m_x;
}
