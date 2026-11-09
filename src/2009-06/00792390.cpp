// from server: 100% by auto
struct I_func_00792390 {
    char pad[648];
    int m_x;
};
struct S_func_00792390 {
    char pad[60];
    I_func_00792390* m_p;
    int f();
};
int S_func_00792390::f()
{
    return m_p->m_x;
}
