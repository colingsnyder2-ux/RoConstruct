// from server: 100% by auto
struct P_func_00695720 { void g(); };
struct S_func_00695720 {
    char pad[180];
    P_func_00695720* m_p;
    void f();
};
void S_func_00695720::f()
{
    m_p->g();
}
