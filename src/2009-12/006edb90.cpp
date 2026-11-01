// from server: 100% by auto
struct P_func_006edb90 { void g(); };
struct S_func_006edb90 {
    char pad[244];
    P_func_006edb90* m_p;
    void f();
};
void S_func_006edb90::f()
{
    m_p->g();
}
