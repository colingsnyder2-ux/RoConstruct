// from server: 100% by auto
struct I_func_00575180 {
    char pad[2124];
    int m_x;
};
struct S_func_00575180 {
    char pad[40];
    I_func_00575180* m_p;
    int f();
};
int S_func_00575180::f()
{
    return m_p->m_x;
}
