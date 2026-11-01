// from server: 100% by auto
struct P_func_005ff520 { void g(); };
struct S_func_005ff520 {
    P_func_005ff520* m_p;
    void f();
};
void S_func_005ff520::f()
{
    m_p->g();
}
