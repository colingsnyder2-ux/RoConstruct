// from server: 100% by auto
struct I_func_0087d850 {
    char pad[648];
    int m_x;
};
struct S_func_0087d850 {
    char pad[60];
    I_func_0087d850* m_p;
    int f();
};
int S_func_0087d850::f()
{
    return m_p->m_x;
}
