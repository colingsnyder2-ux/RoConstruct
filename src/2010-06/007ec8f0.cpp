// from server: 100% by auto
struct P_func_007ec8f0 { void g(); };
struct S_func_007ec8f0 {
    char pad[228];
    P_func_007ec8f0* m_p;
    void f();
};
void S_func_007ec8f0::f()
{
    m_p->g();
}
