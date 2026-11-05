// from server: 100% by auto
struct I_func_0060b410 {
    char pad[100];
    int m_x;
};
struct S_func_0060b410 {
    char pad[36];
    I_func_0060b410* m_p;
    int f();
};
int S_func_0060b410::f()
{
    return m_p->m_x;
}
