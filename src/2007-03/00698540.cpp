// from server: 100% by auto
struct P_func_00698540 { void g(); };
struct S_func_00698540 {
    char pad[444];
    P_func_00698540* m_p;
    void f();
};
void S_func_00698540::f()
{
    m_p->g();
}
