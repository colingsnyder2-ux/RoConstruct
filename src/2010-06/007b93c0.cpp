// from server: 100% by auto
struct I_func_007b93c0 {
    char pad[44];
    int m_x;
};
struct S_func_007b93c0 {
    char pad[252];
    I_func_007b93c0* m_p;
    int f();
};
int S_func_007b93c0::f()
{
    return m_p->m_x;
}
