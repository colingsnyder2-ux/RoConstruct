// from server: 100% by auto
struct P_func_00602870 { void g(); };
struct S_func_00602870 {
    char pad[320];
    P_func_00602870* m_p;
    void f();
};
void S_func_00602870::f()
{
    m_p->g();
}
