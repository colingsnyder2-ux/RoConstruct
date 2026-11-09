// from server: 100% by auto
struct I_func_007750d0 {
    char pad[28];
    int m_x;
};
struct S_func_007750d0 {
    char pad[24];
    I_func_007750d0* m_p;
    int f();
};
int S_func_007750d0::f()
{
    return m_p->m_x;
}
