// from server: 100% by auto
struct P_func_005a9080 { void g(); };
struct S_func_005a9080 {
    char pad[48];
    P_func_005a9080* m_p;
    void f();
};
void S_func_005a9080::f()
{
    m_p->g();
}
