// from server: 100% by auto
struct P_func_006b0e40 { void g(); };
struct S_func_006b0e40 {
    P_func_006b0e40* m_p;
    void f();
};
void S_func_006b0e40::f()
{
    m_p->g();
}
