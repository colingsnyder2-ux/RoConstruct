// from server: 100% by auto
struct I_func_005e7560 {
    char pad[36];
    int m_x;
};
struct S_func_005e7560 {
    char pad[92];
    I_func_005e7560* m_p;
    int f();
};
int S_func_005e7560::f()
{
    return m_p->m_x;
}
