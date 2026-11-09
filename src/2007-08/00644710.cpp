// from server: 100% by auto
struct I_func_00644710 {
    char pad[44];
    int m_x;
};
struct S_func_00644710 {
    char pad[248];
    I_func_00644710* m_p;
    int f();
};
int S_func_00644710::f()
{
    return m_p->m_x;
}
