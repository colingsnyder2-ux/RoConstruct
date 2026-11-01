// from server: 100% by auto
struct P_func_006b0e00 { void g(); };
struct S_func_006b0e00 {
    P_func_006b0e00* m_p;
    void f();
};
void S_func_006b0e00::f()
{
    m_p->g();
}
