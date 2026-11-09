// from server: 100% by auto
struct P_func_00775840 { void g(); };
struct S_func_00775840 {
    char pad[68];
    P_func_00775840* m_p;
    void f();
};
void S_func_00775840::f()
{
    m_p->g();
}
