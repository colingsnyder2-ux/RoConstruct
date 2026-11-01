// from server: 100% by auto
struct P_func_008c3400 { void g(); };
struct S_func_008c3400 {
    char pad[40];
    P_func_008c3400* m_p;
    void f();
};
void S_func_008c3400::f()
{
    m_p->g();
}
