// from server: 100% by auto
struct I_func_008c3420 {
    char pad[2720];
    int m_x;
};
struct S_func_008c3420 {
    char pad[4];
    I_func_008c3420* m_p;
    int f();
};
int S_func_008c3420::f()
{
    return m_p->m_x;
}
