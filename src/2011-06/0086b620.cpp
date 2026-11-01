// from server: 100% by auto
struct P_func_0086b620 { void g(); };
struct S_func_0086b620 {
    char pad[8];
    P_func_0086b620* m_p;
    void f();
};
void S_func_0086b620::f()
{
    m_p->g();
}
