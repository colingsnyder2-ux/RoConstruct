// from server: 100% by auto
struct I_func_0069c650 {
    char pad[460];
    int m_x;
};
struct S_func_0069c650 {
    char pad[612];
    I_func_0069c650* m_p;
    int f();
};
int S_func_0069c650::f()
{
    return m_p->m_x;
}
