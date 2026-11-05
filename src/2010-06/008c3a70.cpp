// from server: 100% by auto
struct I_func_008c3a70 {
    char pad[2132];
    int m_x;
};
struct S_func_008c3a70 {
    char pad[40];
    I_func_008c3a70* m_p;
    int f();
};
int S_func_008c3a70::f()
{
    return m_p->m_x;
}
