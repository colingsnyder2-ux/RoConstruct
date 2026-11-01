// from server: 100% by auto
struct I_func_006bc680 {
    char pad[504];
    int m_x;
};
struct S_func_006bc680 {
    char pad[60];
    I_func_006bc680* m_p;
    int f();
};
int S_func_006bc680::f()
{
    return m_p->m_x;
}
