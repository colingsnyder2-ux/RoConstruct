// from server: 100% by auto
struct I_func_004d7370 {
    char pad[516];
    int m_x;
};
struct S_func_004d7370 {
    char pad[20];
    I_func_004d7370* m_p;
    int f();
};
int S_func_004d7370::f()
{
    return m_p->m_x;
}
