// from server: 100% by auto
struct I_func_0081b900 {
    char pad[324];
    int m_x;
};
struct S_func_0081b900 {
    char pad[176];
    I_func_0081b900* m_p;
    int f();
};
int S_func_0081b900::f()
{
    return m_p->m_x;
}
