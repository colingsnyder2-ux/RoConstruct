// from server: 100% by auto
struct I_func_00639d60 {
    char pad[52];
    int m_x;
};
struct S_func_00639d60 {
    char pad[112];
    I_func_00639d60* m_p;
    int f();
};
int S_func_00639d60::f()
{
    return m_p->m_x;
}
