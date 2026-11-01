// from server: 100% by auto
struct P_func_006b5a60 { void g(); };
struct S_func_006b5a60 {
    char pad[28];
    P_func_006b5a60* m_p;
    void f();
};
void S_func_006b5a60::f()
{
    m_p->g();
}
