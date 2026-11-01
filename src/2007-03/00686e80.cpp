// from server: 100% by auto
struct P_func_00686e80 { void g(); };
struct S_func_00686e80 {
    char pad[176];
    P_func_00686e80* m_p;
    void f();
};
void S_func_00686e80::f()
{
    m_p->g();
}
