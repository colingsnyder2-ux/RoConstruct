// from server: 100% by auto
struct P_func_005abd50 { void g(); };
struct S_func_005abd50 {
    char pad[8];
    P_func_005abd50* m_p;
    void f();
};
void S_func_005abd50::f()
{
    m_p->g();
}
