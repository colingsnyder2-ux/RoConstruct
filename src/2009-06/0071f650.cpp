// from server: 100% by auto
struct I_func_0071f650 {
    char pad[52];
    int m_x;
};
struct S_func_0071f650 {
    char pad[112];
    I_func_0071f650* m_p;
    int f();
};
int S_func_0071f650::f()
{
    return m_p->m_x;
}
