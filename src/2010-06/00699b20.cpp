// from server: 100% by auto
struct P_func_00699b20 { void g(); };
struct S_func_00699b20 {
    char pad[216];
    P_func_00699b20* m_p;
    void f();
};
void S_func_00699b20::f()
{
    m_p->g();
}
