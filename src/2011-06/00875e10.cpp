// from server: 100% by auto
struct I_func_00875e10 {
    char pad[324];
    int m_x;
};
struct S_func_00875e10 {
    char pad[176];
    I_func_00875e10* m_p;
    int f();
};
int S_func_00875e10::f()
{
    return m_p->m_x;
}
