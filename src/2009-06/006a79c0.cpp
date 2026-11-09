// from server: 100% by auto
struct I_func_006a79c0 {
    char pad[40];
    int m_x;
};
struct S_func_006a79c0 {
    char pad[20];
    I_func_006a79c0* m_p;
    int f();
};
int S_func_006a79c0::f()
{
    return m_p->m_x;
}
