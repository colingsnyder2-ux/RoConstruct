// from server: 100% by auto
struct I_func_00714140 {
    char pad[324];
    int m_x;
};
struct S_func_00714140 {
    char pad[176];
    I_func_00714140* m_p;
    int f();
};
int S_func_00714140::f()
{
    return m_p->m_x;
}
