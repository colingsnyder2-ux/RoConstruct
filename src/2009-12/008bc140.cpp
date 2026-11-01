// from server: 100% by auto
struct I_func_008bc140 {
    char pad[288];
    int m_x;
};
struct S_func_008bc140 {
    char pad[284];
    I_func_008bc140* m_p;
    int f();
};
int S_func_008bc140::f()
{
    return m_p->m_x;
}
