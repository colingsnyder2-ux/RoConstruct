// from server: 100% by auto
struct I_func_006f0c90 {
    char pad[2640];
    int m_x;
};
struct S_func_006f0c90 {
    char pad[100];
    I_func_006f0c90* m_p;
    int f();
};
int S_func_006f0c90::f()
{
    return m_p->m_x;
}
