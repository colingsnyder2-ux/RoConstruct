// from server: 100% by auto
struct P_func_007d2960 { void g(); };
struct S_func_007d2960 {
    char pad[256];
    P_func_007d2960* m_p;
    void f();
};
void S_func_007d2960::f()
{
    m_p->g();
}
