// from server: 100% by auto
struct P_func_007eb800 { void g(); };
struct S_func_007eb800 {
    char pad[252];
    P_func_007eb800* m_p;
    void f();
};
void S_func_007eb800::f()
{
    m_p->g();
}
