// from server: 100% by auto
struct I_func_006d4df0 {
    char pad[256];
    int m_x;
};
struct S_func_006d4df0 {
    char pad[36];
    I_func_006d4df0* m_p;
    int f();
};
int S_func_006d4df0::f()
{
    return m_p->m_x;
}
