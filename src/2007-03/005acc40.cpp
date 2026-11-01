// from server: 100% by auto
struct P_func_005acc40 { void g(); };
struct S_func_005acc40 {
    char pad[48];
    P_func_005acc40* m_p;
    void f();
};
void S_func_005acc40::f()
{
    m_p->g();
}
