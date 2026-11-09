// from server: 100% by auto
struct P_func_007030e0 { void g(); };
struct S_func_007030e0 {
    char pad[4];
    P_func_007030e0* m_p;
    void f();
};
void S_func_007030e0::f()
{
    m_p->g();
}
