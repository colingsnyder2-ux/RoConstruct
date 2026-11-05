// from server: 100% by auto
struct P_func_005a0e30 { void g(); };
struct S_func_005a0e30 {
    char pad[740];
    P_func_005a0e30* m_p;
    void f();
};
void S_func_005a0e30::f()
{
    m_p->g();
}
