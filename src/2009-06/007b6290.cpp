// from server: 100% by auto
struct P_func_007b6290 { void g(); };
struct S_func_007b6290 {
    char pad[444];
    P_func_007b6290* m_p;
    void f();
};
void S_func_007b6290::f()
{
    m_p->g();
}
