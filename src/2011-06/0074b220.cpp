// from server: 100% by auto
struct I_func_0074b220 {
    char pad[4];
    int m_x;
};
struct S_func_0074b220 {
    char pad[24];
    I_func_0074b220* m_p;
    int f();
};
int S_func_0074b220::f()
{
    return m_p->m_x;
}
