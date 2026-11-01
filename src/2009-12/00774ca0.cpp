// from server: 100% by auto
struct I_func_00774ca0 {
    char pad[40];
    int m_x;
};
struct S_func_00774ca0 {
    char pad[24];
    I_func_00774ca0* m_p;
    int f();
};
int S_func_00774ca0::f()
{
    return m_p->m_x;
}
