// from server: 100% by auto
struct P_func_006d3030 { void g(); };
struct S_func_006d3030 {
    char pad[180];
    P_func_006d3030* m_p;
    void f();
};
void S_func_006d3030::f()
{
    m_p->g();
}
