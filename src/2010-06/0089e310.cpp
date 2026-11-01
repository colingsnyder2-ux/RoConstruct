// from server: 100% by auto
struct I_func_0089e310 {
    char pad[52];
    int m_x;
};
struct S_func_0089e310 {
    char pad[48];
    I_func_0089e310* m_p;
    int f();
};
int S_func_0089e310::f()
{
    return m_p->m_x;
}
