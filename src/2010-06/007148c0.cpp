// from server: 100% by auto
struct P_func_007148c0 { void g(); };
struct S_func_007148c0 {
    char pad[36];
    P_func_007148c0* m_p;
    void f();
};
void S_func_007148c0::f()
{
    m_p->g();
}
