// from server: 100% by auto
struct I_func_00922340 {
    char pad[2164];
    int m_x;
};
struct S_func_00922340 {
    char pad[12];
    I_func_00922340* m_p;
    int f();
};
int S_func_00922340::f()
{
    return m_p->m_x;
}
