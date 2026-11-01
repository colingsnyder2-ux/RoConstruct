// from server: 100% by auto
struct I_func_0072d220 {
    char pad[20];
    int m_x;
};
struct S_func_0072d220 {
    char pad[376];
    I_func_0072d220* m_p;
    int f();
};
int S_func_0072d220::f()
{
    return m_p->m_x;
}
