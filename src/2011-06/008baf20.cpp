// from server: 100% by auto
struct I_func_008baf20 {
    char pad[20];
    int m_x;
};
struct S_func_008baf20 {
    char pad[144];
    I_func_008baf20* m_p;
    int f();
};
int S_func_008baf20::f()
{
    return m_p->m_x;
}
