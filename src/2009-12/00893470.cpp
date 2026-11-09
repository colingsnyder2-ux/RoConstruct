// from server: 100% by auto
struct P_func_00893470 { void g(); };
struct S_func_00893470 {
    char pad[444];
    P_func_00893470* m_p;
    void f();
};
void S_func_00893470::f()
{
    m_p->g();
}
