// from server: 100% by auto
struct I_func_0091d660 {
    char pad[2764];
    int m_x;
};
struct S_func_0091d660 {
    char pad[12];
    I_func_0091d660* m_p;
    int f();
};
int S_func_0091d660::f()
{
    return m_p->m_x;
}
