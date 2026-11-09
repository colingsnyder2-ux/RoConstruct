// from server: 100% by auto
struct P_func_005a9090 { void g(); };
struct S_func_005a9090 {
    char pad[48];
    P_func_005a9090* m_p;
    void f();
};
void S_func_005a9090::f()
{
    m_p->g();
}
