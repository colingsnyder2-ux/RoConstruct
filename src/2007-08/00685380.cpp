// from server: 100% by auto
struct P_func_00685380 { void g(); };
struct S_func_00685380 {
    char pad[64];
    P_func_00685380* m_p;
    void f();
};
void S_func_00685380::f()
{
    m_p->g();
}
