// from server: 100% by auto
struct I_func_005a5d10 {
    char pad[20];
    int m_x;
};
struct S_func_005a5d10 {
    char pad[156];
    I_func_005a5d10* m_p;
    int f();
};
int S_func_005a5d10::f()
{
    return m_p->m_x;
}
