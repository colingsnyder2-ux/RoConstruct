// from server: 100% by auto
struct P_func_00714150 { void g(); };
struct S_func_00714150 {
    char pad[176];
    P_func_00714150* m_p;
    void f();
};
void S_func_00714150::f()
{
    m_p->g();
}
