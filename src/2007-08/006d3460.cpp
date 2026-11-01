// from server: 100% by auto
struct I_func_006d3460 {
    char pad[512];
    int m_x;
};
struct S_func_006d3460 {
    char pad[60];
    I_func_006d3460* m_p;
    int f();
};
int S_func_006d3460::f()
{
    return m_p->m_x;
}
