// from server: 100% by auto
struct I_func_007e1630 {
    char pad[288];
    int m_x;
};
struct S_func_007e1630 {
    char pad[284];
    I_func_007e1630* m_p;
    int f();
};
int S_func_007e1630::f()
{
    return m_p->m_x;
}
