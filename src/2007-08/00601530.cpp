// from server: 100% by auto
struct P_func_00601530 { void g(); };
struct S_func_00601530 {
    char pad[32];
    P_func_00601530* m_p;
    void f();
};
void S_func_00601530::f()
{
    m_p->g();
}
