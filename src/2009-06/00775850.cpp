// from server: 100% by auto
struct P_func_00775850 { void g(); };
struct S_func_00775850 {
    char pad[68];
    P_func_00775850* m_p;
    void f();
};
void S_func_00775850::f()
{
    m_p->g();
}
