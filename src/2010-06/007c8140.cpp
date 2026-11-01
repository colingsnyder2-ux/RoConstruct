// from server: 100% by auto
struct P_func_007c8140 { void g(); };
struct S_func_007c8140 {
    char pad[188];
    P_func_007c8140* m_p;
    void f();
};
void S_func_007c8140::f()
{
    m_p->g();
}
