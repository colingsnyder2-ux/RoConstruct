// from server: 100% by auto
struct P_func_005ff4b0 { void g(); };
struct S_func_005ff4b0 {
    P_func_005ff4b0* m_p;
    void f();
};
void S_func_005ff4b0::f()
{
    m_p->g();
}
