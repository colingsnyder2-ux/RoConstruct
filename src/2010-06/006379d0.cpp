// from server: 100% by auto
struct P_func_006379d0 { void g(); };
struct S_func_006379d0 {
    char pad[360];
    P_func_006379d0* m_p;
    void f();
};
void S_func_006379d0::f()
{
    m_p->g();
}
