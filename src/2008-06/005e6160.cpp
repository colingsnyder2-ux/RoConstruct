// from server: 100% by auto
struct I_func_005e6160 {
    char pad[160];
    int m_x;
};
struct S_func_005e6160 {
    char pad[28];
    I_func_005e6160* m_p;
    int f();
};
int S_func_005e6160::f()
{
    return m_p->m_x;
}
