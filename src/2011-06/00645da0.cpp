// from server: 100% by auto
struct P_func_00645da0 { void g(); };
struct S_func_00645da0 {
    char pad[152];
    P_func_00645da0* m_p;
    void f();
};
void S_func_00645da0::f()
{
    m_p->g();
}
