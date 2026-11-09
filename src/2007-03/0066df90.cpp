// from server: 100% by auto
struct I_func_0066df90 {
    char pad[128];
    int m_x;
};
struct S_func_0066df90 {
    char pad[132];
    I_func_0066df90* m_p;
    int f();
};
int S_func_0066df90::f()
{
    return m_p->m_x;
}
