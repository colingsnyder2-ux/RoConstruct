// from server: 100% by auto
struct I_func_0091d960 {
    char pad[2168];
    int m_x;
};
struct S_func_0091d960 {
    char pad[64];
    I_func_0091d960* m_p;
    int f();
};
int S_func_0091d960::f()
{
    return m_p->m_x;
}
