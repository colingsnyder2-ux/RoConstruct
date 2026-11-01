// from server: 100% by auto
struct I_func_00689680 {
    char pad[188];
    int m_x;
};
struct S_func_00689680 {
    char pad[140];
    I_func_00689680* m_p;
    int f();
};
int S_func_00689680::f()
{
    return m_p->m_x;
}
