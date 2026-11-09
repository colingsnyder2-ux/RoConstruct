// from server: 100% by auto
struct I_func_006dfd80 {
    char pad[2640];
    int m_x;
};
struct S_func_006dfd80 {
    char pad[100];
    I_func_006dfd80* m_p;
    int f();
};
int S_func_006dfd80::f()
{
    return m_p->m_x;
}
