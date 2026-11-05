// from server: 100% by auto
struct P_func_006760c0 { void g(); };
struct S_func_006760c0 {
    char pad[60];
    P_func_006760c0* m_p;
    void f();
};
void S_func_006760c0::f()
{
    m_p->g();
}
