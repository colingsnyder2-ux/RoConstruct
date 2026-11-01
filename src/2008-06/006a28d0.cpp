// from server: 100% by auto
struct P_func_006a28d0 { void g(); };
struct S_func_006a28d0 {
    char pad[188];
    P_func_006a28d0* m_p;
    void f();
};
void S_func_006a28d0::f()
{
    m_p->g();
}
