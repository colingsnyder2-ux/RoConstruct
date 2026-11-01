// from server: 100% by auto
struct P_func_005fb000 { void g(); };
struct S_func_005fb000 {
    char pad[532];
    P_func_005fb000* m_p;
    void f();
};
void S_func_005fb000::f()
{
    m_p->g();
}
