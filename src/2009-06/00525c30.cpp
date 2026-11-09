// from server: 100% by auto
struct I_func_00525c30 {
    char pad[2168];
    int m_x;
};
struct S_func_00525c30 {
    char pad[56];
    I_func_00525c30* m_p;
    int f();
};
int S_func_00525c30::f()
{
    return m_p->m_x;
}
