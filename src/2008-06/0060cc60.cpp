// from server: 100% by auto
struct P_func_0060cc60 { void g(); };
struct S_func_0060cc60 {
    P_func_0060cc60* m_p;
    void f();
};
void S_func_0060cc60::f()
{
    m_p->g();
}
