// from server: 100% by auto
struct I_func_00701340 {
    char pad[188];
    int m_x;
};
struct S_func_00701340 {
    char pad[144];
    I_func_00701340* m_p;
    int f();
};
int S_func_00701340::f()
{
    return m_p->m_x;
}
