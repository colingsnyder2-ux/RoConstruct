// from server: 100% by auto
struct P_func_005ff510 { void g(); };
struct S_func_005ff510 {
    P_func_005ff510* m_p;
    void f();
};
void S_func_005ff510::f()
{
    m_p->g();
}
