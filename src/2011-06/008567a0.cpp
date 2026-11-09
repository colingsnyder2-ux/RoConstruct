// from server: 100% by auto
struct P_func_008567a0 { void g(); };
struct S_func_008567a0 {
    char pad[256];
    P_func_008567a0* m_p;
    void f();
};
void S_func_008567a0::f()
{
    m_p->g();
}
