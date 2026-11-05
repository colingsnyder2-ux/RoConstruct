// from server: 100% by auto
struct P_func_006b0e60 { void g(); };
struct S_func_006b0e60 {
    P_func_006b0e60* m_p;
    void f();
};
void S_func_006b0e60::f()
{
    m_p->g();
}
