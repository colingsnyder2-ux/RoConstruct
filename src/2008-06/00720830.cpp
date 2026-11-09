// from server: 100% by auto
struct P_func_00720830 { void g(); };
struct S_func_00720830 {
    char pad[444];
    P_func_00720830* m_p;
    void f();
};
void S_func_00720830::f()
{
    m_p->g();
}
