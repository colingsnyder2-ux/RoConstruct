// from server: 100% by auto
struct I_func_005abcc0 {
    char pad[36];
    int m_x;
};
struct S_func_005abcc0 {
    char pad[8];
    I_func_005abcc0* m_p;
    int f();
};
int S_func_005abcc0::f()
{
    return m_p->m_x;
}
