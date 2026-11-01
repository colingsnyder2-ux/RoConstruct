// from server: 100% by auto
struct I_func_0070aa90 {
    char pad[40];
    int m_x;
};
struct S_func_0070aa90 {
    char pad[24];
    I_func_0070aa90* m_p;
    int f();
};
int S_func_0070aa90::f()
{
    return m_p->m_x;
}
