// from server: 100% by auto
struct P_func_006d0690 { void g(); };
struct S_func_006d0690 {
    P_func_006d0690* m_p;
    void f();
};
void S_func_006d0690::f()
{
    m_p->g();
}
