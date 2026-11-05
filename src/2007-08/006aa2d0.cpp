// from server: 100% by auto
struct I_func_006aa2d0 {
    char pad[468];
    int m_x;
};
struct S_func_006aa2d0 {
    char pad[612];
    I_func_006aa2d0* m_p;
    int f();
};
int S_func_006aa2d0::f()
{
    return m_p->m_x;
}
