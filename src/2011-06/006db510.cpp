// from server: 100% by auto
struct P_func_006db510 { void g(); };
struct S_func_006db510 {
    char pad[188];
    P_func_006db510* m_p;
    void f();
};
void S_func_006db510::f()
{
    m_p->g();
}
