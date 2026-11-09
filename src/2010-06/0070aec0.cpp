// from server: 100% by auto
struct I_func_0070aec0 {
    char pad[28];
    int m_x;
};
struct S_func_0070aec0 {
    char pad[24];
    I_func_0070aec0* m_p;
    int f();
};
int S_func_0070aec0::f()
{
    return m_p->m_x;
}
