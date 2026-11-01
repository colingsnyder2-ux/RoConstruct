// from server: 100% by auto
struct P_func_0070d650 { void g(); };
struct S_func_0070d650 {
    char pad[8];
    P_func_0070d650* m_p;
    void f();
};
void S_func_0070d650::f()
{
    m_p->g();
}
