// from server: 100% by auto
struct P_func_0060cc30 { void g(); };
struct S_func_0060cc30 {
    P_func_0060cc30* m_p;
    void f();
};
void S_func_0060cc30::f()
{
    m_p->g();
}
