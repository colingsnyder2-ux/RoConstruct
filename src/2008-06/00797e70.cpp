// from server: 100% by auto
struct I_func_00797e70 {
    char pad[52];
    int m_x;
};
struct S_func_00797e70 {
    char pad[48];
    I_func_00797e70* m_p;
    int f();
};
int S_func_00797e70::f()
{
    return m_p->m_x;
}
