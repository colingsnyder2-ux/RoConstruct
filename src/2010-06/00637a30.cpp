// from server: 100% by auto
struct P_func_00637a30 { void g(); };
struct S_func_00637a30 {
    char pad[360];
    P_func_00637a30* m_p;
    void f();
};
void S_func_00637a30::f()
{
    m_p->g();
}
