// from server: 100% by auto
struct I_func_005750c0 {
    char pad[2704];
    int m_x;
};
struct S_func_005750c0 {
    char pad[16];
    I_func_005750c0* m_p;
    int f();
};
int S_func_005750c0::f()
{
    return m_p->m_x;
}
