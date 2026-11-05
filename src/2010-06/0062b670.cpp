// from server: 100% by auto
struct P_func_0062b670 { void g(); };
struct S_func_0062b670 {
    char pad[32];
    P_func_0062b670* m_p;
    void f();
};
void S_func_0062b670::f()
{
    m_p->g();
}
