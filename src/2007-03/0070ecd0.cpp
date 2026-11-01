// from server: 100% by auto
struct P_func_0070ecd0 { void g(); };
struct S_func_0070ecd0 {
    char pad[112];
    P_func_0070ecd0* m_p;
    void f();
};
void S_func_0070ecd0::f()
{
    m_p->g();
}
