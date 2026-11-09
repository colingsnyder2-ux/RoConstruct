// from server: 100% by auto
struct P_func_004d0460 { void g(); };
struct S_func_004d0460 {
    char pad[176];
    P_func_004d0460* m_p;
    void f();
};
void S_func_004d0460::f()
{
    m_p->g();
}
