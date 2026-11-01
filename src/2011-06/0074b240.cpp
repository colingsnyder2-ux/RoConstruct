// from server: 100% by auto
struct I_func_0074b240 {
    char pad[36];
    int m_x;
};
struct S_func_0074b240 {
    char pad[24];
    I_func_0074b240* m_p;
    int f();
};
int S_func_0074b240::f()
{
    return m_p->m_x;
}
