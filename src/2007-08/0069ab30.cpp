// from server: 100% by auto
struct I_func_0069ab30 {
    char pad[316];
    int m_x;
};
struct S_func_0069ab30 {
    char pad[176];
    I_func_0069ab30* m_p;
    int f();
};
int S_func_0069ab30::f()
{
    return m_p->m_x;
}
