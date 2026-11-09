// from server: 100% by auto
struct I_func_008c6180 {
    char pad[2128];
    int m_x;
};
struct S_func_008c6180 {
    char pad[12];
    I_func_008c6180* m_p;
    int f();
};
int S_func_008c6180::f()
{
    return m_p->m_x;
}
