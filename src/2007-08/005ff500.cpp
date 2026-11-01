// from server: 100% by auto
struct P_func_005ff500 { void g(); };
struct S_func_005ff500 {
    P_func_005ff500* m_p;
    void f();
};
void S_func_005ff500::f()
{
    m_p->g();
}
