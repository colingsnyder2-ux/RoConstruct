// from server: 100% by auto
struct I_func_008973a0 {
    char pad[480];
    int m_x;
};
struct S_func_008973a0 {
    char pad[616];
    I_func_008973a0* m_p;
    int f();
};
int S_func_008973a0::f()
{
    return m_p->m_x;
}
