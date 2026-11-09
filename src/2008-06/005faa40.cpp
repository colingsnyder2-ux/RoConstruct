// from server: 100% by auto
struct I_func_005faa40 {
    char pad[28];
    int m_x;
};
struct S_func_005faa40 {
    char pad[16];
    I_func_005faa40* m_p;
    int f();
};
int S_func_005faa40::f()
{
    return m_p->m_x;
}
