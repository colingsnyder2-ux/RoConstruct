// from server: 100% by auto
struct P_func_0060cc50 { void g(); };
struct S_func_0060cc50 {
    P_func_0060cc50* m_p;
    void f();
};
void S_func_0060cc50::f()
{
    m_p->g();
}
