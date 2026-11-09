// from server: 100% by auto
struct I_func_00870280 {
    char pad[288];
    int m_x;
};
struct S_func_00870280 {
    char pad[284];
    I_func_00870280* m_p;
    int f();
};
int S_func_00870280::f()
{
    return m_p->m_x;
}
