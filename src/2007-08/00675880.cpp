// from server: 100% by auto
struct I_func_00675880 {
    char pad[184];
    int m_x;
};
struct S_func_00675880 {
    char pad[428];
    I_func_00675880* m_p;
    int f();
};
int S_func_00675880::f()
{
    return m_p->m_x;
}
