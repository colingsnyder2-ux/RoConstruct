// from server: 100% by auto
struct P_func_004b9d50 { void g(); };
struct S_func_004b9d50 {
    char pad[64];
    P_func_004b9d50* m_p;
    void f();
};
void S_func_004b9d50::f()
{
    m_p->g();
}
