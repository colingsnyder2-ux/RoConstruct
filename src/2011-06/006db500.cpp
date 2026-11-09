// from server: 100% by auto
struct P_func_006db500 { void g(); };
struct S_func_006db500 {
    char pad[180];
    P_func_006db500* m_p;
    void f();
};
void S_func_006db500::f()
{
    m_p->g();
}
