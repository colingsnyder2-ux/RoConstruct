// from server: 100% by auto
struct P_func_008a0d50 { void g(); };
struct S_func_008a0d50 {
    char pad[52];
    P_func_008a0d50* m_p;
    void f();
};
void S_func_008a0d50::f()
{
    m_p->g();
}
