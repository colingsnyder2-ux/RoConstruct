// from server: 100% by auto
struct I_func_007b8460 {
    char pad[20];
    int m_x;
};
struct S_func_007b8460 {
    char pad[376];
    I_func_007b8460* m_p;
    int f();
};
int S_func_007b8460::f()
{
    return m_p->m_x;
}
