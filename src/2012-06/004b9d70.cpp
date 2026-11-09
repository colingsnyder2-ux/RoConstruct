// from server: 100% by auto
struct I_func_004b9d70 {
    char pad[2756];
    int m_x;
};
struct S_func_004b9d70 {
    char pad[12];
    I_func_004b9d70* m_p;
    int f();
};
int S_func_004b9d70::f()
{
    return m_p->m_x;
}
