// from server: 100% by auto
struct I_func_006f3fc0 {
    char pad[56];
    int m_x;
};
struct S_func_006f3fc0 {
    char pad[88];
    I_func_006f3fc0* m_p;
    int f();
};
int S_func_006f3fc0::f()
{
    return m_p->m_x;
}
