// from server: 100% by auto
struct P_func_00793c50 { void g(); };
struct S_func_00793c50 {
    char pad[132];
    P_func_00793c50* m_p;
    void f();
};
void S_func_00793c50::f()
{
    m_p->g();
}
