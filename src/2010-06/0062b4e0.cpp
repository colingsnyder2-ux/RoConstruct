// from server: 100% by auto
struct P_func_0062b4e0 { void g(); };
struct S_func_0062b4e0 {
    char pad[180];
    P_func_0062b4e0* m_p;
    void f();
};
void S_func_0062b4e0::f()
{
    m_p->g();
}
