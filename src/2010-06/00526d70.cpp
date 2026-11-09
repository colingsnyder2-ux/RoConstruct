// from server: 100% by auto
struct I_func_00526d70 {
    char pad[2720];
    int m_x;
};
struct S_func_00526d70 {
    char pad[48];
    I_func_00526d70* m_p;
    int f();
};
int S_func_00526d70::f()
{
    return m_p->m_x;
}
