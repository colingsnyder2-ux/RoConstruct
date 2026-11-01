// from server: 100% by auto
struct P_func_00643730 { void g(); };
struct S_func_00643730 {
    char pad[40];
    P_func_00643730* m_p;
    void f();
};
void S_func_00643730::f()
{
    m_p->g();
}
