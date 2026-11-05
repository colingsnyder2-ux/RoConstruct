// from server: 100% by auto
struct I_func_0074b230 {
    char pad[20];
    int m_x;
};
struct S_func_0074b230 {
    char pad[24];
    I_func_0074b230* m_p;
    int f();
};
int S_func_0074b230::f()
{
    return m_p->m_x;
}
