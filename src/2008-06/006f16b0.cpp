// from server: 100% by auto
struct P_func_006f16b0 { void g(); };
struct S_func_006f16b0 {
    char pad[256];
    P_func_006f16b0* m_p;
    void f();
};
void S_func_006f16b0::f()
{
    m_p->g();
}
