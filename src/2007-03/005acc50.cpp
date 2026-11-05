// from server: 100% by auto
struct P_func_005acc50 { void g(); };
struct S_func_005acc50 {
    char pad[48];
    P_func_005acc50* m_p;
    void f();
};
void S_func_005acc50::f()
{
    m_p->g();
}
